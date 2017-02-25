//! \brief Extrinsic measures evaluation for overlapping multi-resolution clusterings
//! with possible unequal node base.
//!
//! \license Apache License, Version 2.0: http://www.apache.org/licenses/LICENSE-2.0.html
//! > 	Simple explanation: https://tldrlegal.com/license/apache-license-2.0-(apache-2.0)
//!
//! Copyright (c)
//! \authr Artem Lutov
//! \email luart@ya.ru
//! \date 2017-02-13

#include <cstdio>
#include "cmdline.h"  // Arguments parsing
#include "macrodef.h"
#include "interface.h"


int main(int argc, char **argv)
{
	gengetopt_args_info  args_info;
	auto  err = cmdline_parser(argc, argv, &args_info);
	if(err)
		return err;

	// Validate required xmeasure
	if(!args_info.f1_given && !args_info.nmi_given) {
		fputs("WARNING, no any measures to evaluate specified\n", stderr);
		cmdline_parser_print_help();
		return 1;
	}

	if(args_info.membership_arg <= 0) {
		fprintf(stderr, "ERROR, positive membership is expected: %G\n", args_info.membership_arg);
		return 1;
	}

	{	// Validate the number of input files
		// Note: sync_arg is specified if sync_given
		const auto  inpfiles = args_info.inputs_num + args_info.sync_given;  // The number of input files
		if(inpfiles < 2 || inpfiles > 2 + args_info.sync_given) {
			fputs("ERROR, 2 input clusterings are required with possibly additional"
				" node base, i.e. 2-3 input files in total\n", stderr);
			cmdline_parser_print_help();
			return 1;
		}
		//printf("inpfiles: %i,  sync_base: %s, cn1: %s, cn2: %s\n", args_info.inputs_num
		//	, args_info.sync_given ? args_info.sync_arg : "", args_info.inputs[0]
		//	, args_info.inputs_num >= 2 ? args_info.inputs[1] : args_info.sync_arg);
		//return 1;
	}


	// Load node base if required
	NodeBase  ndbase;
	if(args_info.sync_given && args_info.inputs_num == 2)
		ndbase = NodeBase::load(args_info.sync_arg);

	// Load collections as relations
	AggHash  cn1hash, cn2hash;
	auto cn1 = Collection::load(args_info.inputs[0], &cn1hash, args_info.membership_arg
		, ndbase ? &ndbase : nullptr);
	ndbase.clear();
	auto cn2 = Collection::load(args_info.inputs[1], &cn2hash, args_info.membership_arg
		, args_info.sync_given ? &cn1 : nullptr);

	if(!cn1.ndsnum() || ! cn2.ndsnum()) {
		fprintf(stderr, "WARNING, at least one of the collections is empty, there is nothing"
			" to evaluate. Collection nodes sizes: %u, %u\n", cn1.ndsnum(), cn2.ndsnum());
		return 1;
	}

	// Check the nodebase
	if(cn1hash != cn2hash)
		fprintf(stderr, "WARNING, the nodes in the collections differ: %u nodes"
			" with hash %lu, size: %lu, ids: %lu, id2s: %lu) != %u nodes with hash %lu"
			", size: %lu, ids: %lu, id2s: %lu)\n"
			, cn1.ndsnum(), cn1hash.hash(), cn1hash.size(), cn1hash.idsum(), cn1hash.id2sum()
			, cn2.ndsnum(), cn2hash.hash(), cn2hash.size(), cn2hash.idsum(), cn2hash.id2sum());

	// Evaluate and output measures
	if(args_info.f1_given)
		printf("F1_gm (%s avg of %s, %s evaluation): %G", args_info.unweighted_flag
			? "unweighted" : "weighed", args_info.prob_flag ? "PPs" : "F1s"
			, to_string(Evaluation::MULTIRES).c_str()
			, Collection::f1gm(cn1, cn2, !args_info.unweighted_flag
			, args_info.prob_flag));

	if(args_info.nmi_flag) {
		if(args_info.f1_given)
			fputs("; ", stdout);
		auto rnmi = Collection::nmi(cn1, cn2, args_info.ln_flag);
		const auto  nmix = rnmi.mi / (rnmi.h1 >= rnmi.h2 ? rnmi.h1 : rnmi.h2);
		if(args_info.all_flag)
			printf("NMI_max: %G, NMI_avg: %G, NMI_min: %G", nmix, 2 * rnmi.mi
				/ (rnmi.h1 + rnmi.h2), rnmi.mi / (rnmi.h1 < rnmi.h2 ? rnmi.h1 : rnmi.h2));
		else printf("NMI_max: %G", nmix);
		printf(" for %s evaluation", to_string(rnmi.eval).c_str());
	}
	puts("");  // \n

    return 0;
}

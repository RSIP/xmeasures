/*
  File autogenerated by gengetopt version 2.22.6
  generated with the following command:
  gengetopt --output-dir autogen -i args.ggo --default-optional --unamed-opts=clusterings

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FIX_UNUSED
#define FIX_UNUSED(X) (void) (X) /* avoid warnings for unused params */
#endif

#include <getopt.h>

#include "cmdline.h"

const char *gengetopt_args_info_purpose = "Extrinsic measures evaluation: F1 (prob, harm and score) for overlapping\nmulti-resolution clusterings with possible unequal node base and standard NMI\nfor non-overlapping clustering on a single resolution.";

const char *gengetopt_args_info_usage = "Usage: xmeasures [OPTIONS] clustering1 clustering2\n\n  clustering  - input file, collection of the clusters to be evaluated.\n  \nExample:\n  $ ./xmeasures -fp -kc networks/5K25.cnl tests/5K25_l0.825/5K25_l0.825_796.cnl\n";

const char *gengetopt_args_info_versiontext = "";

const char *gengetopt_args_info_description = "Extrinsic measures are evaluated, i.e. clustering (collection of clusters) is\ncompared to another clustering, which can be the ground-truth.\nNOTE: Each cluster should contain unique members, which is verified only in the\ndebug mode.\nEvaluating measures are:\n\n  - F1  - various F1 measures of the Greatest (Max) Match including the Average\nF1-Score with optional weighting.\n NOTE: There are 3 matching policies available for each kind of F1. The most\nrepresentative evaluation is performed by the F1p with combined matching\npolicy (considers both micro and macro weightings). \n\n  - NMI  - Normalized Mutual Information, normalized by either max or also\nsqrt, avg and min information content denominators.\nATTENTION: This is standard NMI, which should be used ONLY for the HARD\npartitioning evaluation (non-overlapping clustering on a single resolution).\nIt penalizes overlapping and multi-resolution structures.\nNOTE: Unequal node base in the clusterings is allowed, it penalizes the\nmatch.Use [OvpNMI](https://github.com/eXascaleInfolab/OvpNMI) or\n[GenConvNMI](https://github.com/eXascaleInfolab/GenConvNMI) for NMI evaluation\nin the arbitrary collections (still each cluster should contain unique\nmembers).\n";

const char *gengetopt_args_info_help[] = {
  "  -h, --help              Print help and exit",
  "  -V, --version           Print version and exit",
  "  -o, --ovp               evaluate overlapping instead of multi-resolution\n                            clusters, where max matching for any shared member\n                            between R overlapping clusters is 1/R unlike 1 for\n                            the member existing in R distinct clusters on R\n                            resolutions  (default=off)",
  "  -s, --sync=filename     synchronize with the node base, skipping the\n                            non-matching nodes.\n                            NOTE: the node base can be either a separate, or an\n                            evaluating CNL file, in the latter case this option\n                            should precede the evaluating filename not\n                            repeating it",
  "  -m, --membership=FLOAT  average expected membership of the nodes in the\n                            clusters, > 0, typically >= 1. Used only for the\n                            containers preallocation facilitating estimation of\n                            the nodes number if not specified in the file\n                            header.  (default=`1')",
  "  -d, --detailed          detailed (verbose) results output  (default=off)",
  "\nF1 Options:",
  "  -f, --f1[=ENUM]         evaluate F1 of the [weighted] average of the greatest\n                            (maximal) match by F1 or partial probability.\n                            NOTE: F1p <= F1h <= F1s, where:\n                             - p (F1p)  - Harmonic mean of the [weighted]\n                            average of Partial Probabilities, the most\n                            discriminative and satisfies the largest number of\n                            the Formal Constraints (homogeneity, completeness,\n                            rag bag,  size/quantity, balance);\n                             - h (F1h)  - Harmonic mean of the [weighted]\n                            average of F1s;\n                             - s (F1s)  - Arithmetic mean (average) of the\n                            [weighted] average of F1s, Standard F1-Score, the\n                            least discriminative and satisfies the lowest\n                            number of the Formal Constraints.\n                              (possible values=\"partprob\", \"harmonic\",\n                            \"standard\" default=`partprob')",
  "  -k, --kind[=ENUM]       kind of the matching policy:\n                             - w  - weighted (default)\n                             - u  - unweighed\n                             - c  - combined(w, u) using geometric mean\n                               (possible values=\"weighted\", \"unweighed\",\n                            \"combined\" default=`weighted')",
  "\nNMI Options:",
  "  -n, --nmi               evaluate NMI (Normalized Mutual Information)\n                            (default=off)",
  "  -a, --all               evaluate all NMIs using sqrt, avg and min\n                            denominators besides the max one  (default=off)",
  "  -e, --ln                use ln (exp base) instead of log2 (Shannon entropy,\n                            bits) for the information measuring  (default=off)",
    0
};

typedef enum {ARG_NO
  , ARG_FLAG
  , ARG_STRING
  , ARG_FLOAT
  , ARG_ENUM
} cmdline_parser_arg_type;

static
void clear_given (struct gengetopt_args_info *args_info);
static
void clear_args (struct gengetopt_args_info *args_info);

static int
cmdline_parser_internal (int argc, char **argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error);

static int
cmdline_parser_required2 (struct gengetopt_args_info *args_info, const char *prog_name, const char *additional_error);

const char *cmdline_parser_f1_values[] = {"partprob", "harmonic", "standard", 0}; /*< Possible values for f1. */
const char *cmdline_parser_kind_values[] = {"weighted", "unweighed", "combined", 0}; /*< Possible values for kind. */

static char *
gengetopt_strdup (const char *s);

static
void clear_given (struct gengetopt_args_info *args_info)
{
  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->ovp_given = 0 ;
  args_info->sync_given = 0 ;
  args_info->membership_given = 0 ;
  args_info->detailed_given = 0 ;
  args_info->f1_given = 0 ;
  args_info->kind_given = 0 ;
  args_info->nmi_given = 0 ;
  args_info->all_given = 0 ;
  args_info->ln_given = 0 ;
}

static
void clear_args (struct gengetopt_args_info *args_info)
{
  FIX_UNUSED (args_info);
  args_info->ovp_flag = 0;
  args_info->sync_arg = NULL;
  args_info->sync_orig = NULL;
  args_info->membership_arg = 1;
  args_info->membership_orig = NULL;
  args_info->detailed_flag = 0;
  args_info->f1_arg = f1_arg_partprob;
  args_info->f1_orig = NULL;
  args_info->kind_arg = kind_arg_weighted;
  args_info->kind_orig = NULL;
  args_info->nmi_flag = 0;
  args_info->all_flag = 0;
  args_info->ln_flag = 0;
  
}

static
void init_args_info(struct gengetopt_args_info *args_info)
{


  args_info->help_help = gengetopt_args_info_help[0] ;
  args_info->version_help = gengetopt_args_info_help[1] ;
  args_info->ovp_help = gengetopt_args_info_help[2] ;
  args_info->sync_help = gengetopt_args_info_help[3] ;
  args_info->membership_help = gengetopt_args_info_help[4] ;
  args_info->detailed_help = gengetopt_args_info_help[5] ;
  args_info->f1_help = gengetopt_args_info_help[7] ;
  args_info->kind_help = gengetopt_args_info_help[8] ;
  args_info->nmi_help = gengetopt_args_info_help[10] ;
  args_info->all_help = gengetopt_args_info_help[11] ;
  args_info->ln_help = gengetopt_args_info_help[12] ;
  
}

void
cmdline_parser_print_version (void)
{
  printf ("%s %s\n",
     (strlen(CMDLINE_PARSER_PACKAGE_NAME) ? CMDLINE_PARSER_PACKAGE_NAME : CMDLINE_PARSER_PACKAGE),
     CMDLINE_PARSER_VERSION);

  if (strlen(gengetopt_args_info_versiontext) > 0)
    printf("\n%s\n", gengetopt_args_info_versiontext);
}

static void print_help_common(void) {
  cmdline_parser_print_version ();

  if (strlen(gengetopt_args_info_purpose) > 0)
    printf("\n%s\n", gengetopt_args_info_purpose);

  if (strlen(gengetopt_args_info_usage) > 0)
    printf("\n%s\n", gengetopt_args_info_usage);

  printf("\n");

  if (strlen(gengetopt_args_info_description) > 0)
    printf("%s\n\n", gengetopt_args_info_description);
}

void
cmdline_parser_print_help (void)
{
  int i = 0;
  print_help_common();
  while (gengetopt_args_info_help[i])
    printf("%s\n", gengetopt_args_info_help[i++]);
}

void
cmdline_parser_init (struct gengetopt_args_info *args_info)
{
  clear_given (args_info);
  clear_args (args_info);
  init_args_info (args_info);

  args_info->inputs = 0;
  args_info->inputs_num = 0;
}

void
cmdline_parser_params_init(struct cmdline_parser_params *params)
{
  if (params)
    { 
      params->override = 0;
      params->initialize = 1;
      params->check_required = 1;
      params->check_ambiguity = 0;
      params->print_errors = 1;
    }
}

struct cmdline_parser_params *
cmdline_parser_params_create(void)
{
  struct cmdline_parser_params *params = 
    (struct cmdline_parser_params *)malloc(sizeof(struct cmdline_parser_params));
  cmdline_parser_params_init(params);  
  return params;
}

static void
free_string_field (char **s)
{
  if (*s)
    {
      free (*s);
      *s = 0;
    }
}


static void
cmdline_parser_release (struct gengetopt_args_info *args_info)
{
  unsigned int i;
  free_string_field (&(args_info->sync_arg));
  free_string_field (&(args_info->sync_orig));
  free_string_field (&(args_info->membership_orig));
  free_string_field (&(args_info->f1_orig));
  free_string_field (&(args_info->kind_orig));
  
  
  for (i = 0; i < args_info->inputs_num; ++i)
    free (args_info->inputs [i]);

  if (args_info->inputs_num)
    free (args_info->inputs);

  clear_given (args_info);
}

/**
 * @param val the value to check
 * @param values the possible values
 * @return the index of the matched value:
 * -1 if no value matched,
 * -2 if more than one value has matched
 */
static int
check_possible_values(const char *val, const char *values[])
{
  int i, found, last;
  size_t len;

  if (!val)   /* otherwise strlen() crashes below */
    return -1; /* -1 means no argument for the option */

  found = last = 0;

  for (i = 0, len = strlen(val); values[i]; ++i)
    {
      if (strncmp(val, values[i], len) == 0)
        {
          ++found;
          last = i;
          if (strlen(values[i]) == len)
            return i; /* exact macth no need to check more */
        }
    }

  if (found == 1) /* one match: OK */
    return last;

  return (found ? -2 : -1); /* return many values or none matched */
}


static void
write_into_file(FILE *outfile, const char *opt, const char *arg, const char *values[])
{
  int found = -1;
  if (arg) {
    if (values) {
      found = check_possible_values(arg, values);      
    }
    if (found >= 0)
      fprintf(outfile, "%s=\"%s\" # %s\n", opt, arg, values[found]);
    else
      fprintf(outfile, "%s=\"%s\"\n", opt, arg);
  } else {
    fprintf(outfile, "%s\n", opt);
  }
}


int
cmdline_parser_dump(FILE *outfile, struct gengetopt_args_info *args_info)
{
  int i = 0;

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot dump options to stream\n", CMDLINE_PARSER_PACKAGE);
      return EXIT_FAILURE;
    }

  if (args_info->help_given)
    write_into_file(outfile, "help", 0, 0 );
  if (args_info->version_given)
    write_into_file(outfile, "version", 0, 0 );
  if (args_info->ovp_given)
    write_into_file(outfile, "ovp", 0, 0 );
  if (args_info->sync_given)
    write_into_file(outfile, "sync", args_info->sync_orig, 0);
  if (args_info->membership_given)
    write_into_file(outfile, "membership", args_info->membership_orig, 0);
  if (args_info->detailed_given)
    write_into_file(outfile, "detailed", 0, 0 );
  if (args_info->f1_given)
    write_into_file(outfile, "f1", args_info->f1_orig, cmdline_parser_f1_values);
  if (args_info->kind_given)
    write_into_file(outfile, "kind", args_info->kind_orig, cmdline_parser_kind_values);
  if (args_info->nmi_given)
    write_into_file(outfile, "nmi", 0, 0 );
  if (args_info->all_given)
    write_into_file(outfile, "all", 0, 0 );
  if (args_info->ln_given)
    write_into_file(outfile, "ln", 0, 0 );
  

  i = EXIT_SUCCESS;
  return i;
}

int
cmdline_parser_file_save(const char *filename, struct gengetopt_args_info *args_info)
{
  FILE *outfile;
  int i = 0;

  outfile = fopen(filename, "w");

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot open file for writing: %s\n", CMDLINE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  i = cmdline_parser_dump(outfile, args_info);
  fclose (outfile);

  return i;
}

void
cmdline_parser_free (struct gengetopt_args_info *args_info)
{
  cmdline_parser_release (args_info);
}

/** @brief replacement of strdup, which is not standard */
char *
gengetopt_strdup (const char *s)
{
  char *result = 0;
  if (!s)
    return result;

  result = (char*)malloc(strlen(s) + 1);
  if (result == (char*)0)
    return (char*)0;
  strcpy(result, s);
  return result;
}

int
cmdline_parser (int argc, char **argv, struct gengetopt_args_info *args_info)
{
  return cmdline_parser2 (argc, argv, args_info, 0, 1, 1);
}

int
cmdline_parser_ext (int argc, char **argv, struct gengetopt_args_info *args_info,
                   struct cmdline_parser_params *params)
{
  int result;
  result = cmdline_parser_internal (argc, argv, args_info, params, 0);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser2 (int argc, char **argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required)
{
  int result;
  struct cmdline_parser_params params;
  
  params.override = override;
  params.initialize = initialize;
  params.check_required = check_required;
  params.check_ambiguity = 0;
  params.print_errors = 1;

  result = cmdline_parser_internal (argc, argv, args_info, &params, 0);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required (struct gengetopt_args_info *args_info, const char *prog_name)
{
  int result = EXIT_SUCCESS;

  if (cmdline_parser_required2(args_info, prog_name, 0) > 0)
    result = EXIT_FAILURE;

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required2 (struct gengetopt_args_info *args_info, const char *prog_name, const char *additional_error)
{
  int error_occurred = 0;
  FIX_UNUSED (additional_error);

  /* checks for required options */
  
  /* checks for dependences among options */
  if (args_info->kind_given && ! args_info->f1_given)
    {
      fprintf (stderr, "%s: '--kind' ('-k') option depends on option 'f1'%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  if (args_info->all_given && ! args_info->nmi_given)
    {
      fprintf (stderr, "%s: '--all' ('-a') option depends on option 'nmi'%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  if (args_info->ln_given && ! args_info->nmi_given)
    {
      fprintf (stderr, "%s: '--ln' ('-e') option depends on option 'nmi'%s\n", prog_name, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }

  return error_occurred;
}


static char *package_name = 0;

/**
 * @brief updates an option
 * @param field the generic pointer to the field to update
 * @param orig_field the pointer to the orig field
 * @param field_given the pointer to the number of occurrence of this option
 * @param prev_given the pointer to the number of occurrence already seen
 * @param value the argument for this option (if null no arg was specified)
 * @param possible_values the possible values for this option (if specified)
 * @param default_value the default value (in case the option only accepts fixed values)
 * @param arg_type the type of this option
 * @param check_ambiguity @see cmdline_parser_params.check_ambiguity
 * @param override @see cmdline_parser_params.override
 * @param no_free whether to free a possible previous value
 * @param multiple_option whether this is a multiple option
 * @param long_opt the corresponding long option
 * @param short_opt the corresponding short option (or '-' if none)
 * @param additional_error possible further error specification
 */
static
int update_arg(void *field, char **orig_field,
               unsigned int *field_given, unsigned int *prev_given, 
               char *value, const char *possible_values[],
               const char *default_value,
               cmdline_parser_arg_type arg_type,
               int check_ambiguity, int override,
               int no_free, int multiple_option,
               const char *long_opt, char short_opt,
               const char *additional_error)
{
  char *stop_char = 0;
  const char *val = value;
  int found;
  char **string_field;
  FIX_UNUSED (field);

  stop_char = 0;
  found = 0;

  if (!multiple_option && prev_given && (*prev_given || (check_ambiguity && *field_given)))
    {
      if (short_opt != '-')
        fprintf (stderr, "%s: `--%s' (`-%c') option given more than once%s\n", 
               package_name, long_opt, short_opt,
               (additional_error ? additional_error : ""));
      else
        fprintf (stderr, "%s: `--%s' option given more than once%s\n", 
               package_name, long_opt,
               (additional_error ? additional_error : ""));
      return 1; /* failure */
    }

  if (possible_values && (found = check_possible_values((value ? value : default_value), possible_values)) < 0)
    {
      if (short_opt != '-')
        fprintf (stderr, "%s: %s argument, \"%s\", for option `--%s' (`-%c')%s\n", 
          package_name, (found == -2) ? "ambiguous" : "invalid", value, long_opt, short_opt,
          (additional_error ? additional_error : ""));
      else
        fprintf (stderr, "%s: %s argument, \"%s\", for option `--%s'%s\n", 
          package_name, (found == -2) ? "ambiguous" : "invalid", value, long_opt,
          (additional_error ? additional_error : ""));
      return 1; /* failure */
    }
    
  if (field_given && *field_given && ! override)
    return 0;
  if (prev_given)
    (*prev_given)++;
  if (field_given)
    (*field_given)++;
  if (possible_values)
    val = possible_values[found];

  switch(arg_type) {
  case ARG_FLAG:
    *((int *)field) = !*((int *)field);
    break;
  case ARG_FLOAT:
    if (val) *((float *)field) = (float)strtod (val, &stop_char);
    break;
  case ARG_ENUM:
    if (val) *((int *)field) = found;
    break;
  case ARG_STRING:
    if (val) {
      string_field = (char **)field;
      if (!no_free && *string_field)
        free (*string_field); /* free previous string */
      *string_field = gengetopt_strdup (val);
    }
    break;
  default:
    break;
  };

  /* check numeric conversion */
  switch(arg_type) {
  case ARG_FLOAT:
    if (val && !(stop_char && *stop_char == '\0')) {
      fprintf(stderr, "%s: invalid numeric value: %s\n", package_name, val);
      return 1; /* failure */
    }
    break;
  default:
    ;
  };

  /* store the original value */
  switch(arg_type) {
  case ARG_NO:
  case ARG_FLAG:
    break;
  default:
    if (value && orig_field) {
      if (no_free) {
        *orig_field = value;
      } else {
        if (*orig_field)
          free (*orig_field); /* free previous string */
        *orig_field = gengetopt_strdup (value);
      }
    }
  };

  return 0; /* OK */
}


int
cmdline_parser_internal (
  int argc, char **argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error)
{
  int c;	/* Character of the parsed option.  */

  int error_occurred = 0;
  struct gengetopt_args_info local_args_info;
  
  int override;
  int initialize;
  int check_required;
  int check_ambiguity;
  
  package_name = argv[0];
  
  override = params->override;
  initialize = params->initialize;
  check_required = params->check_required;
  check_ambiguity = params->check_ambiguity;

  if (initialize)
    cmdline_parser_init (args_info);

  cmdline_parser_init (&local_args_info);

  optarg = 0;
  optind = 0;
  opterr = params->print_errors;
  optopt = '?';

  while (1)
    {
      int option_index = 0;

      static struct option long_options[] = {
        { "help",	0, NULL, 'h' },
        { "version",	0, NULL, 'V' },
        { "ovp",	0, NULL, 'o' },
        { "sync",	1, NULL, 's' },
        { "membership",	1, NULL, 'm' },
        { "detailed",	0, NULL, 'd' },
        { "f1",	2, NULL, 'f' },
        { "kind",	2, NULL, 'k' },
        { "nmi",	0, NULL, 'n' },
        { "all",	0, NULL, 'a' },
        { "ln",	0, NULL, 'e' },
        { 0,  0, 0, 0 }
      };

      c = getopt_long (argc, argv, "hVos:m:df::k::nae", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'h':	/* Print help and exit.  */
          cmdline_parser_print_help ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'V':	/* Print version and exit.  */
          cmdline_parser_print_version ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'o':	/* evaluate overlapping instead of multi-resolution clusters, where max matching for any shared member between R overlapping clusters is 1/R unlike 1 for the member existing in R distinct clusters on R resolutions.  */
        
        
          if (update_arg((void *)&(args_info->ovp_flag), 0, &(args_info->ovp_given),
              &(local_args_info.ovp_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "ovp", 'o',
              additional_error))
            goto failure;
        
          break;
        case 's':	/* synchronize with the node base, skipping the non-matching nodes.
        NOTE: the node base can be either a separate, or an evaluating CNL file, in the latter case this option should precede the evaluating filename not repeating it.  */
        
        
          if (update_arg( (void *)&(args_info->sync_arg), 
               &(args_info->sync_orig), &(args_info->sync_given),
              &(local_args_info.sync_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "sync", 's',
              additional_error))
            goto failure;
        
          break;
        case 'm':	/* average expected membership of the nodes in the clusters, > 0, typically >= 1. Used only for the containers preallocation facilitating estimation of the nodes number if not specified in the file header..  */
        
        
          if (update_arg( (void *)&(args_info->membership_arg), 
               &(args_info->membership_orig), &(args_info->membership_given),
              &(local_args_info.membership_given), optarg, 0, "1", ARG_FLOAT,
              check_ambiguity, override, 0, 0,
              "membership", 'm',
              additional_error))
            goto failure;
        
          break;
        case 'd':	/* detailed (verbose) results output.  */
        
        
          if (update_arg((void *)&(args_info->detailed_flag), 0, &(args_info->detailed_given),
              &(local_args_info.detailed_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "detailed", 'd',
              additional_error))
            goto failure;
        
          break;
        case 'f':	/* evaluate F1 of the [weighted] average of the greatest (maximal) match by F1 or partial probability.
        NOTE: F1p <= F1h <= F1s, where:
         - p (F1p)  - Harmonic mean of the [weighted] average of Partial Probabilities, the most discriminative and satisfies the largest number of the Formal Constraints (homogeneity, completeness, rag bag,  size/quantity, balance);
         - h (F1h)  - Harmonic mean of the [weighted] average of F1s;
         - s (F1s)  - Arithmetic mean (average) of the [weighted] average of F1s, Standard F1-Score, the least discriminative and satisfies the lowest number of the Formal Constraints.
.  */
        
        
          if (update_arg( (void *)&(args_info->f1_arg), 
               &(args_info->f1_orig), &(args_info->f1_given),
              &(local_args_info.f1_given), optarg, cmdline_parser_f1_values, "partprob", ARG_ENUM,
              check_ambiguity, override, 0, 0,
              "f1", 'f',
              additional_error))
            goto failure;
        
          break;
        case 'k':	/* kind of the matching policy:
         - w  - weighted (default)
         - u  - unweighed
         - c  - combined(w, u) using geometric mean
         .  */
        
        
          if (update_arg( (void *)&(args_info->kind_arg), 
               &(args_info->kind_orig), &(args_info->kind_given),
              &(local_args_info.kind_given), optarg, cmdline_parser_kind_values, "weighted", ARG_ENUM,
              check_ambiguity, override, 0, 0,
              "kind", 'k',
              additional_error))
            goto failure;
        
          break;
        case 'n':	/* evaluate NMI (Normalized Mutual Information).  */
        
        
          if (update_arg((void *)&(args_info->nmi_flag), 0, &(args_info->nmi_given),
              &(local_args_info.nmi_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "nmi", 'n',
              additional_error))
            goto failure;
        
          break;
        case 'a':	/* evaluate all NMIs using sqrt, avg and min denominators besides the max one.  */
        
        
          if (update_arg((void *)&(args_info->all_flag), 0, &(args_info->all_given),
              &(local_args_info.all_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "all", 'a',
              additional_error))
            goto failure;
        
          break;
        case 'e':	/* use ln (exp base) instead of log2 (Shannon entropy, bits) for the information measuring.  */
        
        
          if (update_arg((void *)&(args_info->ln_flag), 0, &(args_info->ln_given),
              &(local_args_info.ln_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "ln", 'e',
              additional_error))
            goto failure;
        
          break;

        case 0:	/* Long option with no short option */
        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          goto failure;

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c%s\n", CMDLINE_PARSER_PACKAGE, c, (additional_error ? additional_error : ""));
          abort ();
        } /* switch */
    } /* while */



  if (check_required)
    {
      error_occurred += cmdline_parser_required2 (args_info, argv[0], additional_error);
    }

  cmdline_parser_release (&local_args_info);

  if ( error_occurred )
    return (EXIT_FAILURE);

  if (optind < argc)
    {
      int i = 0 ;
      int found_prog_name = 0;
      /* whether program name, i.e., argv[0], is in the remaining args
         (this may happen with some implementations of getopt,
          but surely not with the one included by gengetopt) */

      i = optind;
      while (i < argc)
        if (argv[i++] == argv[0]) {
          found_prog_name = 1;
          break;
        }
      i = 0;

      args_info->inputs_num = argc - optind - found_prog_name;
      args_info->inputs =
        (char **)(malloc ((args_info->inputs_num)*sizeof(char *))) ;
      while (optind < argc)
        if (argv[optind++] != argv[0])
          args_info->inputs[ i++ ] = gengetopt_strdup (argv[optind-1]) ;
    }

  return 0;

failure:
  
  cmdline_parser_release (&local_args_info);
  return (EXIT_FAILURE);
}

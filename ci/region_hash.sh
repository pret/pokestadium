# Source this file, then: region_hash ROOT VERSION
#
# Prints a digest of everything that decides a version's split: its yaml and
# symbol files (not the generated linker_scripts/<v>/auto) plus the top-level
# linker scripts. The region baseline cache is only reused when the digest of
# the checkout under test equals the one recorded when the cache was built.
region_hash() {
    ( cd "$1" && {
        find "yamls/$2" "linker_scripts/$2" -type f -not -path '*/auto/*' 2>/dev/null
        find linker_scripts -maxdepth 1 -type f
    } | LC_ALL=C sort | xargs md5sum | md5sum | cut -d' ' -f1 )
}

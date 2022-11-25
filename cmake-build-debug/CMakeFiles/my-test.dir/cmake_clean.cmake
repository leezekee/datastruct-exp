file(REMOVE_RECURSE
  "../bin/my-test.exe"
  "../bin/my-test.exe.manifest"
  "../bin/my-test.pdb"
  "../lib/libmy-test.dll.a"
  "CMakeFiles/my-test.dir/example/my-test.cpp.obj"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/my-test.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()

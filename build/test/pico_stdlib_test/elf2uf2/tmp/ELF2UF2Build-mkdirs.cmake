# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/volse/Nextcloud/Alles_nur_geCloud/Kreationen/Volse/BERT/code/tests/pico-sdk/tools/elf2uf2"
  "/home/volse/Nextcloud/Alles_nur_geCloud/Kreationen/Volse/BERT/build/elf2uf2"
  "/home/volse/Nextcloud/Alles_nur_geCloud/Kreationen/Volse/BERT/build/test/pico_stdlib_test/elf2uf2"
  "/home/volse/Nextcloud/Alles_nur_geCloud/Kreationen/Volse/BERT/build/test/pico_stdlib_test/elf2uf2/tmp"
  "/home/volse/Nextcloud/Alles_nur_geCloud/Kreationen/Volse/BERT/build/test/pico_stdlib_test/elf2uf2/src/ELF2UF2Build-stamp"
  "/home/volse/Nextcloud/Alles_nur_geCloud/Kreationen/Volse/BERT/build/test/pico_stdlib_test/elf2uf2/src"
  "/home/volse/Nextcloud/Alles_nur_geCloud/Kreationen/Volse/BERT/build/test/pico_stdlib_test/elf2uf2/src/ELF2UF2Build-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/volse/Nextcloud/Alles_nur_geCloud/Kreationen/Volse/BERT/build/test/pico_stdlib_test/elf2uf2/src/ELF2UF2Build-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/volse/Nextcloud/Alles_nur_geCloud/Kreationen/Volse/BERT/build/test/pico_stdlib_test/elf2uf2/src/ELF2UF2Build-stamp${cfgdir}") # cfgdir has leading slash
endif()

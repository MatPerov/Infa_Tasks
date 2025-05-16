set(animals "cat;mouse;dog;elephant;tiger;lion;axolotl;hippo;squirrel;wolf;shark;whale;bee;sloth;sheep;giraffe;scorpion")

file(MAKE_DIRECTORY animal_files)

foreach(animal IN LISTS animals)
  set(filename "animal_files/${animal}.txt")
  file(WRITE "${filename}")
endforeach()

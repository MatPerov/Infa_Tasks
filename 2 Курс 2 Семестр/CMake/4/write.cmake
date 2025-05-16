set(animals "cat;mouse;dog;elephant;tiger;lion;axolotl;hippo;squirrel;wolf;shark;whale;bee;sloth;sheep;giraffe;scorpion")
foreach(animal IN LISTS animals)
  message("${animal}")
endforeach()
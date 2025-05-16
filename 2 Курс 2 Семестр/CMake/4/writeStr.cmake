set(animals "cat;mouse;dog;elephant;tiger;lion;axolotl;hippo;squirrel;wolf;shark;whale;bee;sloth;sheep;giraffe;scorpion")

string(JOIN " " joined_animals ${animals})
message("${joined_animals}")
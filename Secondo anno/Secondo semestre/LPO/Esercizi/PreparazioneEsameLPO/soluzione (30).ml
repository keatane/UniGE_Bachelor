let rec find el = function
  hd::tl -> (if el=hd then 1 else 0)+find el tl
| _ -> 0;;

find "a" ["a";"c";"c"] = 1;;

find "c" ["a";"c";"c"] = 2;;

find "c" ["a";"b";"c"] = 1;;

find "d" ["a";"b";"c"] = 0;;

let acc_find el =
   let rec aux acc = function
      hd::tl -> aux(if el=hd then acc+1 else acc) tl
| _ -> acc
   in aux 0;;

acc_find "a" ["a";"c";"c"] = 1;;

acc_find "c" ["a";"c";"c"] = 2;;

acc_find "c" ["a";"b";"c"] = 1;;

acc_find "d" ["a";"b";"c"] = 0;;

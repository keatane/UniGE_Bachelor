let l1 = [(1, "one"); (2, "two"); (3, "three")];;
let l2 = [("one", 1); ("two", 2); ("three", 3)];;

let rec unzip = function
    (hd1,_)::tl -> hd1::unzip tl
  | _ -> [];;

unzip l1 = [1; 2; 3];;
unzip l2 = ["one"; "two"; "three"];;

let acc_unzip l = 
  let rec aux acc = function
      (hd1,_)::tl -> aux (hd1::acc) tl
    | _ -> List.rev acc
  in aux [] l;;

acc_unzip l1 = unzip l1;; 
acc_unzip l2 = unzip l2;; 

let map_unzip l = List.map (fun (hd1,_) -> hd1) l;;

map_unzip l1 = unzip l1;; 
map_unzip l2 = unzip l2;; 


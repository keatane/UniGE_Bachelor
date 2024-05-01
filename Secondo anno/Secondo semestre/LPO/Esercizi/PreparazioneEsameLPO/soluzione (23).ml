
let rec gen_prod f = function
    [] -> 1
  | h::t -> f h * gen_prod f t;;

gen_prod (fun x->x+2) [];;
gen_prod (fun x->x+2) [1];;
gen_prod (fun x->x+2) [1;2];;
gen_prod (fun x->x+2) [1;2;3];;


let acc_gen_prod f = 
  let rec aux acc = function
      [] -> acc 
    | h::t -> aux (acc*f h) t 
  in aux 1;;

gen_prod (fun x->x+2) [1;2;3] = 60;;

acc_gen_prod (fun x->x+2) [1;2;3] = gen_prod (fun x->x+2) [1;2;3];;

let fold_gen_prod f = List.fold_left (fun a e -> a*f e) 1;;

fold_gen_prod (fun x->x+2) [1;2;3] = gen_prod (fun x->x+2) [1;2;3];;


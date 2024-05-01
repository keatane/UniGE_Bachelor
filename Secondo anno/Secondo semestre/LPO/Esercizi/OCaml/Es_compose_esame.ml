(* let rec compose a = function f::t-> f (compose a t) | _ -> a;; *)
(* la chiamata ricorsiva permette di far eseguire prima la seconda funzione passata *)



(* let compose a l = let rec aux acc = function f::t -> aux (f acc) t | _ -> acc
     in aux a (List.rev l);;
*)
(* in questo caso devo manualmente passare la seconda funzione come primo elemento *)



let compose a l = List.fold_left (fun acc f -> f acc) a (List.rev l);;


compose 2 [(fun x -> x*2); (fun x -> x+1)];;

compose 2 [(fun x -> x+1); (fun x -> x*2)];;
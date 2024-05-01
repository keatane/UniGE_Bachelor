let rec limit n = function 
    [] -> [] |
    h::t -> if n<=0 then [] else h::limit (n-1) t;;

limit (-1) [1;2];;

limit 0 [1;2];;

limit 1 [1;2];;

limit 2 [1;2];;

limit 3 [1;2];;

let acc_limit n l = 
  let rec aux a n = function
      [] -> a |
      h::t -> if n<=0 then a else aux (h::a) (n-1) t  
  in
    List.rev(aux [] n l);;

acc_limit (-1) [1;2];;

acc_limit (0) [1;2];;

acc_limit (1) [1;2];;

acc_limit (2) [1;2];;

acc_limit (3) [1;2];;


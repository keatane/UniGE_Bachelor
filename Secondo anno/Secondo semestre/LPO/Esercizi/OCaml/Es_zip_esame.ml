let rec zip l1 l2 = let rec aux acc l1 l2 = match l1,l2 with 
      x::y, h::t -> aux ((x, h) :: acc) y t
    | _ -> List.rev acc
  in aux l1 l2;;
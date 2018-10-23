(* top-down merge sort *)
fun merge_sort xs =
  case xs of
    ([] | [_]) => xs
  | _ => let
           val m = length xs
           val left = List.take (xs, m div 2)
           val right = List.drop (xs, m div 2)
           fun merge (l, r) =
             (* base case: either left or right list is null *)
             if null l orelse null r
             then l @ r
             else
               if hd l < hd r
               then hd l :: merge (tl l, r)
               else hd r :: merge (l, tl r)
         in
             merge (merge_sort left, merge_sort right)
         end

(define (curried-map f)
  (letrec ([g
            (lambda (xs)
              (if (null? xs)
              null
              (cons (f (car xs)) (g (cdr xs)))))])
    g))
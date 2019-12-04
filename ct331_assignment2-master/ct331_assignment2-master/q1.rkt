#lang racket
(cons 1 2)
(cons '1(cons '2(cons '3'())))
(cons (cons "This is a string" 2 )(cons '1(cons '2(cons '3'()))))
(list (list "This is also string" (list 2 ) (list 1 2 3)))
(append '("Once again this is string") '(2) '(1 2 3))
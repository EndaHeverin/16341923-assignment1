#lang racket

(define (make-bin-tree-leaf E)
  "Create a leaf."
  (list E))

(define (make-bin-tree-node E B1 B2)
  (list E B1 B2))

(make-bin-tree-node '*
                             (make-bin-tree-node '+
                                                 (make-bin-tree-leaf 2)
                                                 (make-bin-tree-leaf 3))
                             (make-bin-tree-node '-
                                                 (make-bin-tree-leaf 7)
                                                 (make-bin-tree-leaf 8)))
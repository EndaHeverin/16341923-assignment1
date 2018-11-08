#lang racket
;Part A
(define (ins_beg el lst)
  (cons el lst))
(ins_beg '(a) '(b c d))
(ins_beg '(a b)'(b c d))
;Part B
 (define (ins_end el lst)
  (append lst el))
(ins_end '(a) '(b c d))
(ins_end '(a b)'(b c d))
;Part C
(define (count_top_level lst)
  (cond ((null? lst) 0)
        ((not (pair? lst))1)
        (else (+ (count_top_level (car lst))
                 (count_top_level (cdr lst))))))
(count_top_level '(b c d))

;Part D
(define (count_instances lst el)
      (cond ((null? lst) 0)
          ((= (car lst) el) (+ 1 (count_instances (cdr lst) el)))
          (else (count_instances (cdr lst) el))))
(count_instances '(1 2 3 2 1) 2)
;Part F
;(define (count_instances_tr lst el)
 ;     (cond ((null? lst) 0)
  ;          (sub lst el)
  ;        ))
  ;(define (sub lst el)
   ; ((= (car lst) el) (+ 1 (count_instances (cdr lst) el)))
    ;      (else (sub (cdr lst) el)))
;(count_instances '(1 2 3 2 1) 2)
(define (treeduce pair-fn atom-fn tree)
  (if (pair? tree)
      (pair-fn (treeduce pair-fn atom-fn (car tree))
               (treeduce pair-fn atom-fn (cdr tree)))
      (atom-fn tree)))
(define (count_instance_deep tree)
  (treeduce +
            (lambda (atom) 
              (if (not (null? atom))
                  1
                  0))
            tree))

(count_instance_deep '(1 (1 1) 1))

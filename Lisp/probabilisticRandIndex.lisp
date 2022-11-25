;; Copyright 2022 Giovanni Romano and Claudio Carpineto

;; Permission is hereby granted, free of charge, to any person obtaining a copy
;; of this software and associated documentation files (the "Software"), to deal
;; in the Software without restriction, including without limitation the rights
;; to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
;; copies of the Software, and to permit persons to whom the Software is
;; furnished to do so, subject to the following conditions:

;; The above copyright notice and this permission notice shall be included in
;; all copies or substantial portions of the Software.

;; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
;; IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
;; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
;; THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
;; LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
;; OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


;; clustering1 is a vector with the classes of the objects
;; clustering2 is a vector with the classes of the objects
;; the result is the probabilistic rand index of clustering1 and clustering2

(defun probabilistic-rand-index (clustering1 clustering2)
  (let ((n (length clustering1)) (m1 1) (m2 1)
	(n11 0) (n10 0) (n01 0) (n00 0)
	w11 w10 w01 w00)
    ;; m1 is the number of classes in clustering1
    ;; m2 is the number of classes in clustering2
    ;; nij is the number of pairs of objects that satisfy the two properties:
    ;; n11 same class in clustering1 AND same class in clustering2
    ;; n10 same class in clustering1 AND different classes in clustering2
    ;; n01 different classes in clustering1 AND same class in clustering2
    ;; n00 different classes in clustering1 AND different classes in clustering2
    ;; w11 is the probabilistic weight of n11
    ;; w10 is the probabilistic weight of n10
    ;; w01 is the probabilistic weight of n01
    ;; w00 is the probabilistic weight of n00  
    (loop for object-i from 0 to (- n 2)
	  do
	     (loop for object-j from (+ object-i 1) to (- n 1)
		   with objectI-clustering1-class-last = 't
		   with objectI-clustering2-class-last = 't
		   do
		      (cond
			((eq (aref clustering1 object-i) (aref clustering1 object-j))
			 (setq objectI-clustering1-class-last nil)
			 (cond
			   ((eq (aref clustering2 object-i) (aref clustering2 object-j))
			    (setq objectI-clustering2-class-last nil)
			    (incf n11))
			   (t (incf n10))))
			((eq (aref clustering2 object-i) (aref clustering2 object-j))
			 (setq objectI-clustering2-class-last nil)
			 (incf n01))
			(t (incf n00)))
		   finally (when objectI-clustering1-class-last (incf m1))
			   (when objectI-clustering2-class-last (incf m2))))
    (setq w11 (- (log (/ 1.0 (* m1 m2)) 2)))
    (cond
      ((> m2 1)
       (setq w10 (- (log (/ (- m2 1.0) (* m1 m2)) 2))))
      (t (setq w10 0.0)))
    (cond
      ((> m1 1)
       (setq w01 (- (log (/ (- m1 1.0) (* m1 m2)) 2))))
      (t (setq w01 0.0)))
    (cond
      ((and (> m2 1) (> m1 1))
       (setq w00 (- (log (/ (* (- m1 1.0) (- m2 1.0)) (* m1 m2)) 2))))
      (t (setq w00 0.0)))
    (/ (+ (* w11 n11) (* w00 n00))
       (+ (* w11 n11) (* w10 n10) (* w01 n01) (* w00 n00)))))



#|============= example =============

;; Create clustering 1
(defvar c1 #(1 2 1 1 2 2 1 2 1 2))

;; Create clustering 2
(defvar c2 #(3 1 1 1 1 2 3 1 2 1))

;; Compute Probabilistic Rand Index (PRI = 0.5212565)
(probabilistic-rand-index c1 c2)

|#



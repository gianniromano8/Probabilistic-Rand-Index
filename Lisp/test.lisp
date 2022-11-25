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



;; Equal partitions (PRI = 1)
(defvar c1 #(1 2 1 1 2 2 1 2 1 2))
(defvar c2 #(1 2 1 1 2 2 1 2 1 2))
(probabilistic-rand-index c1 c2)


;; Totally different partitions (PRI = 0)
(defvar c3 #(1 2 3 4 5 6 7 8 9 10))
(defvar c4 #(1 1 1 1 1 1 1 1 1 1))
(probabilistic-rand-index c3 c4)


;; Similar partitions (PRI = 0.81897455)
(defvar c5 #(1 1 1 1 1 2 2 2 2 2))
(defvar c6 #(1 1 1 1 3 2 2 2 2 3))
(probabilistic-rand-index c5 c6)


;; Dissimilar partitions (PRI = 0.38048342)
(defvar c7 #(1 1 1 1 1 2 2 2 2 2))
(defvar c8 #(1 2 3 4 5 1 2 3 4 5))
(probabilistic-rand-index c7 c8)


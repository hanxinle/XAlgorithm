;do
(defun jiecheng(n)
  (do((i 1(+ i 1))
      (r 1(* r i)))
      ((> i n)r)))
;when 
(defun oddnumber(n)
	(when (oddp n)
	  (format t "hmm,odd NO.")
	  (+ n 1)))

;case
(defun month-number(mon)
  (case mon
    ((1 3 5 7 8 10 12) 31)
    ((4 6 9 11) 30)
    (2 29)
    (otherwise "unkonwn month")))

;; (for i 1  4 (format t "hello")
(defmacro for (var start stop &body body)
	   (let ((gstop (gensym)))
	     `(do ((,var ,start (1+ ,var))
		   (,gstop ,stop))
		  ((> ,var ,gstop))
		,@body)))
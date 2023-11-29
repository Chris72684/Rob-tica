;; Auto-generated. Do not edit!


(when (boundp 'beginner_tutorials::Distancia)
  (if (not (find-package "BEGINNER_TUTORIALS"))
    (make-package "BEGINNER_TUTORIALS"))
  (shadow 'Distancia (find-package "BEGINNER_TUTORIALS")))
(unless (find-package "BEGINNER_TUTORIALS::DISTANCIA")
  (make-package "BEGINNER_TUTORIALS::DISTANCIA"))
(unless (find-package "BEGINNER_TUTORIALS::DISTANCIAREQUEST")
  (make-package "BEGINNER_TUTORIALS::DISTANCIAREQUEST"))
(unless (find-package "BEGINNER_TUTORIALS::DISTANCIARESPONSE")
  (make-package "BEGINNER_TUTORIALS::DISTANCIARESPONSE"))

(in-package "ROS")





(defclass beginner_tutorials::DistanciaRequest
  :super ros::object
  :slots (_x1 _y1 _x2 _y2 ))

(defmethod beginner_tutorials::DistanciaRequest
  (:init
   (&key
    ((:x1 __x1) 0.0)
    ((:y1 __y1) 0.0)
    ((:x2 __x2) 0.0)
    ((:y2 __y2) 0.0)
    )
   (send-super :init)
   (setq _x1 (float __x1))
   (setq _y1 (float __y1))
   (setq _x2 (float __x2))
   (setq _y2 (float __y2))
   self)
  (:x1
   (&optional __x1)
   (if __x1 (setq _x1 __x1)) _x1)
  (:y1
   (&optional __y1)
   (if __y1 (setq _y1 __y1)) _y1)
  (:x2
   (&optional __x2)
   (if __x2 (setq _x2 __x2)) _x2)
  (:y2
   (&optional __y2)
   (if __y2 (setq _y2 __y2)) _y2)
  (:serialization-length
   ()
   (+
    ;; float64 _x1
    8
    ;; float64 _y1
    8
    ;; float64 _x2
    8
    ;; float64 _y2
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _x1
       (sys::poke _x1 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y1
       (sys::poke _y1 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _x2
       (sys::poke _x2 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y2
       (sys::poke _y2 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _x1
     (setq _x1 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y1
     (setq _y1 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _x2
     (setq _x2 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y2
     (setq _y2 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass beginner_tutorials::DistanciaResponse
  :super ros::object
  :slots (_dis ))

(defmethod beginner_tutorials::DistanciaResponse
  (:init
   (&key
    ((:dis __dis) 0.0)
    )
   (send-super :init)
   (setq _dis (float __dis))
   self)
  (:dis
   (&optional __dis)
   (if __dis (setq _dis __dis)) _dis)
  (:serialization-length
   ()
   (+
    ;; float64 _dis
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _dis
       (sys::poke _dis (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _dis
     (setq _dis (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass beginner_tutorials::Distancia
  :super ros::object
  :slots ())

(setf (get beginner_tutorials::Distancia :md5sum-) "0ceadde973f9e22e63aec3f9a9e20a83")
(setf (get beginner_tutorials::Distancia :datatype-) "beginner_tutorials/Distancia")
(setf (get beginner_tutorials::Distancia :request) beginner_tutorials::DistanciaRequest)
(setf (get beginner_tutorials::Distancia :response) beginner_tutorials::DistanciaResponse)

(defmethod beginner_tutorials::DistanciaRequest
  (:response () (instance beginner_tutorials::DistanciaResponse :init)))

(setf (get beginner_tutorials::DistanciaRequest :md5sum-) "0ceadde973f9e22e63aec3f9a9e20a83")
(setf (get beginner_tutorials::DistanciaRequest :datatype-) "beginner_tutorials/DistanciaRequest")
(setf (get beginner_tutorials::DistanciaRequest :definition-)
      "float64 x1
float64 y1
float64 x2
float64 y2
---
float64 dis
")

(setf (get beginner_tutorials::DistanciaResponse :md5sum-) "0ceadde973f9e22e63aec3f9a9e20a83")
(setf (get beginner_tutorials::DistanciaResponse :datatype-) "beginner_tutorials/DistanciaResponse")
(setf (get beginner_tutorials::DistanciaResponse :definition-)
      "float64 x1
float64 y1
float64 x2
float64 y2
---
float64 dis
")



(provide :beginner_tutorials/Distancia "0ceadde973f9e22e63aec3f9a9e20a83")



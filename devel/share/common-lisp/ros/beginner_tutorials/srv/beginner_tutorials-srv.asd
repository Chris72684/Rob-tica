
(cl:in-package :asdf)

(defsystem "beginner_tutorials-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Distancia" :depends-on ("_package_Distancia"))
    (:file "_package_Distancia" :depends-on ("_package"))
  ))
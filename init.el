;; Added by Package.el.  This must come before configurations of
;; installed packages.  Don't delete this line.  If you don't want it,
;; just comment it out by adding a semicolon to the start of the line.
;; You may delete these explanatory comments.
(require 'package)
(let* ((no-ssl (and (memq system-type '(windows-nt ms-dos))
                    (not (gnutls-available-p))))
       (proto (if no-ssl "http" "https")))
  ;; Comment/uncomment these two lines to enable/disable MELPA and MELPA Stable as desired
  (add-to-list 'package-archives (cons "melpa" (concat proto "://melpa.org/packages/")) t)
  ;;(add-to-list 'package-archives (cons "melpa-stable" (concat proto "://stable.melpa.org/packages/")) t)
  (when (< emacs-major-version 24)
    ;; For important compatibility libraries like cl-lib
    (add-to-list 'package-archives '("gnu" . (concat proto "://elpa.gnu.org/packages/")))))
(package-initialize)


;;back-up-files
(setq backup-directory-alist '(("." . "~/.saves")))
(setq delete-old-versions t
      kept-new-versions 6
      kept-old-versions 2
      version-control t)


;; Neo-tree
(global-set-key [f8] 'neotree-toggle)
;; auto-complete-mode
(ac-config-default)
;; linum-mode
(global-linum-mode 1)


;; elpy
(elpy-enable)
;; jedi
(add-hook 'python-mode-hook 'jedi:setup)
(setq jedi:complete-on-dot t)


;; Load linux style c source
(add-to-list 'load-path
	     "~/.emacs.d/myEl/")
(load "linux-c")
;; etags file name
(defun mytag ()
  (setq tags-file-name
	(concat default-directory "TAGS")))
(add-hook 'c-mode-hook 'mytag)
(define-key global-map "\M-*" 'pop-tag-mark)


;; yasnippet mode
(yas-global-mode 1)


(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(package-selected-packages
   (quote
    (neotree projectile auto-complete concurrent ctable deferred epc jedi-core popup python-environment jedi find-file-in-project highlight-indentation ivy pyvenv s elpy yasnippet))))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(default ((t (:family "Monaco" :foundry "apple" :slant normal :weight normal :height 143 :width normal)))))

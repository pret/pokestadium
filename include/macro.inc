.macro glabel label
    .global \label
    \label:
.endm

.macro jlabel label
    .global \label
    \label:
.endm

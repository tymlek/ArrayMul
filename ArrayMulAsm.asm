; array_mul_asm procedure				(ArrayMulAsm.asm)

.586
.model flat, C
array_mul_asm Proto, arrayPtr:Ptr DWord, multiplier:DWord, count:DWord

.code
;------------------------------------------------------------------------------
; Multiplies each integer in an array by multiplier.
; Receives: arrayPtr - pointer to the array,
;			multipler - 32-bit multiplier,
;			count - the array lenght.
; Returns: Nothing.
;------------------------------------------------------------------------------
array_mul_asm Proc Uses eax ecx esi edi,
					arrayPtr:Ptr DWord,
					multiplier:DWord,
					count:DWord
	mov esi,arrayPtr
	mov edi,esi
	mov ecx,count
	cld

	L1:
		lodsd
		mul multiplier
		stosd
	Loop L1

	ret
array_mul_asm EndP
End

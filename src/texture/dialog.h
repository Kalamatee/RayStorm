#ifndef DIALOG_H
#define DIALOG_H

typedef ULONG DIALOG_ELEMENT;

#define DE(a) (DIALOG_ELEMENT)(a)

enum
{
	DIALOG_VGROUP,
	DIALOG_HGROUP,
	DIALOG_COLGROUP,
	DIALOG_END,
	DIALOG_FINISH,
	DIALOG_LABEL,
	DIALOG_COLORBOX,
	DIALOG_SLIDER,
	DIALOG_FLOAT,
	DIALOG_NUMBER,
	DIALOG_NUMBER_POSITIVE,
	DIALOG_CHECKBOX,
	DIALOG_IMAGE
};

#endif // DIALOG_H

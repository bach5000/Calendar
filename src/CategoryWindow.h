/*
 * Copyright 2017 Akshay Agarwal, agarwal.akshay.akshay8@gmail.com
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef CATEGORYWINDOW_H
#define CATEGORYWINDOW_H

#include <Window.h>

class BButton;
class BListView;
class BScrollView;
class BView;
class Category;
class CategoryEditWindow;


const uint32 kCategoryWindowQuitting = 'kcwq';


class CategoryWindow: public BWindow {
public:
				CategoryWindow();

	virtual void		MessageReceived(BMessage* message);
	virtual bool		QuitRequested();

	BList*				GetCategoryList();
	BListView*			GetListView();
	void				LoadCategories();

private:
	void			_OpenCategoryWindow(Category* category);

	static const uint32	kAddPressed		= 1000;
	static const uint32	kCancelPressed		= 1001;
	static const uint32	kCategorySelected	= 1002;

	BView*			fMainView;
	BListView*		fCategoryListView;
	BScrollView*		fCategoryScroll;
	BButton*		fAddButton;
	BButton*		fCancelButton;
	CategoryEditWindow*	fCategoryEditWindow;

	BList*			fCategoryList;

};


#endif

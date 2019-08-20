/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Standard.hxx>
#include <Interface_GTool.hxx>
#include <Standard_Handle.hxx>
#include <Interface_Protocol.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Interface_Category.hxx>

void bind_Interface_Category(py::module &mod){

py::class_<Interface_Category, std::unique_ptr<Interface_Category>> cls_Interface_Category(mod, "Interface_Category", "This class manages categories A category is defined by a name and a number, and can be seen as a way of rough classification, i.e. less precise than a cdl type. Hence, it is possible to dispatch every entity in about a dozen of categories, twenty is a reasonable maximum.");

// Constructors
cls_Interface_Category.def(py::init<>());
cls_Interface_Category.def(py::init<const opencascade::handle<Interface_Protocol> &>(), py::arg("theProtocol"));
cls_Interface_Category.def(py::init<const opencascade::handle<Interface_GTool> &>(), py::arg("theGTool"));

// Fields

// Methods
// cls_Interface_Category.def_static("operator new_", (void * (*)(size_t)) &Interface_Category::operator new, "None", py::arg("theSize"));
// cls_Interface_Category.def_static("operator delete_", (void (*)(void *)) &Interface_Category::operator delete, "None", py::arg("theAddress"));
// cls_Interface_Category.def_static("operator new[]_", (void * (*)(size_t)) &Interface_Category::operator new[], "None", py::arg("theSize"));
// cls_Interface_Category.def_static("operator delete[]_", (void (*)(void *)) &Interface_Category::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_Category.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_Category::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_Category.def_static("operator delete_", (void (*)(void *, void *)) &Interface_Category::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_Category.def("SetProtocol", (void (Interface_Category::*)(const opencascade::handle<Interface_Protocol> &)) &Interface_Category::SetProtocol, "Sets/Changes Protocol", py::arg("theProtocol"));
cls_Interface_Category.def("CatNum", (Standard_Integer (Interface_Category::*)(const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &)) &Interface_Category::CatNum, "Determines the Category Number for an entity in its context, by using general service CategoryNumber", py::arg("theEnt"), py::arg("theShares"));
cls_Interface_Category.def("ClearNums", (void (Interface_Category::*)()) &Interface_Category::ClearNums, "Clears the recorded list of category numbers for a Model");
cls_Interface_Category.def("Compute", (void (Interface_Category::*)(const opencascade::handle<Interface_InterfaceModel> &, const Interface_ShareTool &)) &Interface_Category::Compute, "Computes the Category Number for each entity and records it, in an array (ent.number -> category number) Hence, it can be queried by the method Num. The Model itself is not recorded, this method is intended to be used in a wider context (which detains also a Graph, etc)", py::arg("theModel"), py::arg("theShares"));
cls_Interface_Category.def("Num", (Standard_Integer (Interface_Category::*)(const Standard_Integer) const) &Interface_Category::Num, "Returns the category number recorded for an entity number Returns 0 if out of range", py::arg("theNumEnt"));
cls_Interface_Category.def_static("AddCategory_", (Standard_Integer (*)(const Standard_CString)) &Interface_Category::AddCategory, "Records a new Category defined by its names, produces a number New if not yet recorded", py::arg("theName"));
cls_Interface_Category.def_static("NbCategories_", (Standard_Integer (*)()) &Interface_Category::NbCategories, "Returns the count of recorded categories");
cls_Interface_Category.def_static("Name_", (Standard_CString (*)(const Standard_Integer)) &Interface_Category::Name, "Returns the name of a category, according to its number", py::arg("theNum"));
cls_Interface_Category.def_static("Number_", (Standard_Integer (*)(const Standard_CString)) &Interface_Category::Number, "Returns the number of a category, according to its name", py::arg("theName"));
cls_Interface_Category.def_static("Init_", (void (*)()) &Interface_Category::Init, "Default initialisation (protected against several calls : passes only once)");

// Enums

}
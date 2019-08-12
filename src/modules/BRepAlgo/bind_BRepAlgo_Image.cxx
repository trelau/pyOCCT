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
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <BRepAlgo_Image.hxx>

void bind_BRepAlgo_Image(py::module &mod){

py::class_<BRepAlgo_Image, std::unique_ptr<BRepAlgo_Image, Deleter<BRepAlgo_Image>>> cls_BRepAlgo_Image(mod, "BRepAlgo_Image", "Stores link between a shape <S> and a shape <NewS> obtained from <S>. <NewS> is an image of <S>.");

// Constructors
cls_BRepAlgo_Image.def(py::init<>());

// Fields

// Methods
// cls_BRepAlgo_Image.def_static("operator new_", (void * (*)(size_t)) &BRepAlgo_Image::operator new, "None", py::arg("theSize"));
// cls_BRepAlgo_Image.def_static("operator delete_", (void (*)(void *)) &BRepAlgo_Image::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgo_Image.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgo_Image::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgo_Image.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgo_Image::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgo_Image.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgo_Image::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgo_Image.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgo_Image::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgo_Image.def("SetRoot", (void (BRepAlgo_Image::*)(const TopoDS_Shape &)) &BRepAlgo_Image::SetRoot, "None", py::arg("S"));
cls_BRepAlgo_Image.def("Bind", (void (BRepAlgo_Image::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_Image::Bind, "Links <NewS> as image of <OldS>.", py::arg("OldS"), py::arg("NewS"));
cls_BRepAlgo_Image.def("Bind", (void (BRepAlgo_Image::*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &BRepAlgo_Image::Bind, "Links <NewS> as image of <OldS>.", py::arg("OldS"), py::arg("NewS"));
cls_BRepAlgo_Image.def("Add", (void (BRepAlgo_Image::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_Image::Add, "Add <NewS> to the image of <OldS>.", py::arg("OldS"), py::arg("NewS"));
cls_BRepAlgo_Image.def("Add", (void (BRepAlgo_Image::*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &BRepAlgo_Image::Add, "Add <NewS> to the image of <OldS>.", py::arg("OldS"), py::arg("NewS"));
cls_BRepAlgo_Image.def("Clear", (void (BRepAlgo_Image::*)()) &BRepAlgo_Image::Clear, "None");
cls_BRepAlgo_Image.def("Remove", (void (BRepAlgo_Image::*)(const TopoDS_Shape &)) &BRepAlgo_Image::Remove, "Remove <S> to set of images.", py::arg("S"));
cls_BRepAlgo_Image.def("Roots", (const TopTools_ListOfShape & (BRepAlgo_Image::*)() const) &BRepAlgo_Image::Roots, "None");
cls_BRepAlgo_Image.def("IsImage", (Standard_Boolean (BRepAlgo_Image::*)(const TopoDS_Shape &) const) &BRepAlgo_Image::IsImage, "None", py::arg("S"));
cls_BRepAlgo_Image.def("ImageFrom", (const TopoDS_Shape & (BRepAlgo_Image::*)(const TopoDS_Shape &) const) &BRepAlgo_Image::ImageFrom, "Returns the generator of <S>", py::arg("S"));
cls_BRepAlgo_Image.def("Root", (const TopoDS_Shape & (BRepAlgo_Image::*)(const TopoDS_Shape &) const) &BRepAlgo_Image::Root, "Returns the upper generator of <S>", py::arg("S"));
cls_BRepAlgo_Image.def("HasImage", (Standard_Boolean (BRepAlgo_Image::*)(const TopoDS_Shape &) const) &BRepAlgo_Image::HasImage, "None", py::arg("S"));
cls_BRepAlgo_Image.def("Image", (const TopTools_ListOfShape & (BRepAlgo_Image::*)(const TopoDS_Shape &) const) &BRepAlgo_Image::Image, "Returns the Image of <S>. Returns <S> in the list if HasImage(S) is false.", py::arg("S"));
cls_BRepAlgo_Image.def("LastImage", (void (BRepAlgo_Image::*)(const TopoDS_Shape &, TopTools_ListOfShape &) const) &BRepAlgo_Image::LastImage, "Stores in <L> the images of images of...images of <S>. <L> contains only <S> if HasImage(S) is false.", py::arg("S"), py::arg("L"));
cls_BRepAlgo_Image.def("Compact", (void (BRepAlgo_Image::*)()) &BRepAlgo_Image::Compact, "Keeps only the link between roots and lastimage.");
cls_BRepAlgo_Image.def("Filter", (void (BRepAlgo_Image::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &BRepAlgo_Image::Filter, "Deletes in the images the shape of type <ShapeType> which are not in <S>. Warning: Compact() must be call before.", py::arg("S"), py::arg("ShapeType"));

// Enums

}
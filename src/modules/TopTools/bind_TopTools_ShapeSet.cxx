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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_LocationSet.hxx>
#include <Standard_OStream.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_IStream.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_Handle.hxx>
#include <Message_ProgressIndicator.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_ShapeSet.hxx>

void bind_TopTools_ShapeSet(py::module &mod){

py::class_<TopTools_ShapeSet, std::unique_ptr<TopTools_ShapeSet, Deleter<TopTools_ShapeSet>>> cls_TopTools_ShapeSet(mod, "TopTools_ShapeSet", "A ShapeSets contains a Shape and all its sub-shapes and locations. It can be dump, write and read.");

// Constructors
cls_TopTools_ShapeSet.def(py::init<>());

// Fields

// Methods
// cls_TopTools_ShapeSet.def_static("operator new_", (void * (*)(size_t)) &TopTools_ShapeSet::operator new, "None", py::arg("theSize"));
// cls_TopTools_ShapeSet.def_static("operator delete_", (void (*)(void *)) &TopTools_ShapeSet::operator delete, "None", py::arg("theAddress"));
// cls_TopTools_ShapeSet.def_static("operator new[]_", (void * (*)(size_t)) &TopTools_ShapeSet::operator new[], "None", py::arg("theSize"));
// cls_TopTools_ShapeSet.def_static("operator delete[]_", (void (*)(void *)) &TopTools_ShapeSet::operator delete[], "None", py::arg("theAddress"));
// cls_TopTools_ShapeSet.def_static("operator new_", (void * (*)(size_t, void *)) &TopTools_ShapeSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopTools_ShapeSet.def_static("operator delete_", (void (*)(void *, void *)) &TopTools_ShapeSet::operator delete, "None", py::arg(""), py::arg(""));
cls_TopTools_ShapeSet.def("SetFormatNb", (void (TopTools_ShapeSet::*)(const Standard_Integer)) &TopTools_ShapeSet::SetFormatNb, "None", py::arg("theFormatNb"));
cls_TopTools_ShapeSet.def("FormatNb", (Standard_Integer (TopTools_ShapeSet::*)() const) &TopTools_ShapeSet::FormatNb, "two formats available for the moment: First: does not write CurveOnSurface UV Points into the file on reading calls Check() method. Second: stores CurveOnSurface UV Points. On reading format is recognized from Version string.");
cls_TopTools_ShapeSet.def("Clear", (void (TopTools_ShapeSet::*)()) &TopTools_ShapeSet::Clear, "Clears the content of the set. This method can be redefined.");
cls_TopTools_ShapeSet.def("Add", (Standard_Integer (TopTools_ShapeSet::*)(const TopoDS_Shape &)) &TopTools_ShapeSet::Add, "Stores <S> and its sub-shape. Returns the index of <S>. The method AddGeometry is called on each sub-shape.", py::arg("S"));
cls_TopTools_ShapeSet.def("Shape", (const TopoDS_Shape & (TopTools_ShapeSet::*)(const Standard_Integer) const) &TopTools_ShapeSet::Shape, "Returns the sub-shape of index <I>.", py::arg("I"));
cls_TopTools_ShapeSet.def("Index", (Standard_Integer (TopTools_ShapeSet::*)(const TopoDS_Shape &) const) &TopTools_ShapeSet::Index, "Returns the index of <S>.", py::arg("S"));
cls_TopTools_ShapeSet.def("Locations", (const TopTools_LocationSet & (TopTools_ShapeSet::*)() const) &TopTools_ShapeSet::Locations, "None");
cls_TopTools_ShapeSet.def("ChangeLocations", (TopTools_LocationSet & (TopTools_ShapeSet::*)()) &TopTools_ShapeSet::ChangeLocations, "None");
cls_TopTools_ShapeSet.def("DumpExtent", (Standard_OStream & (TopTools_ShapeSet::*)(Standard_OStream &) const) &TopTools_ShapeSet::DumpExtent, "Dumps the number of objects in me on the stream <OS>. (Number of shapes of each type)", py::arg("OS"));
cls_TopTools_ShapeSet.def("DumpExtent", (void (TopTools_ShapeSet::*)(TCollection_AsciiString &) const) &TopTools_ShapeSet::DumpExtent, "Dumps the number of objects in me in the string S (Number of shapes of each type)", py::arg("S"));
cls_TopTools_ShapeSet.def("Dump", (void (TopTools_ShapeSet::*)(Standard_OStream &) const) &TopTools_ShapeSet::Dump, "Dumps the content of me on the stream <OS>.", py::arg("OS"));
cls_TopTools_ShapeSet.def("Write", (void (TopTools_ShapeSet::*)(Standard_OStream &)) &TopTools_ShapeSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
cls_TopTools_ShapeSet.def("Read", (void (TopTools_ShapeSet::*)(Standard_IStream &)) &TopTools_ShapeSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
cls_TopTools_ShapeSet.def("Dump", (void (TopTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const) &TopTools_ShapeSet::Dump, "Dumps on <OS> the shape <S>. Dumps the orientation, the index of the TShape and the index of the Location.", py::arg("S"), py::arg("OS"));
cls_TopTools_ShapeSet.def("Write", (void (TopTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const) &TopTools_ShapeSet::Write, "Writes on <OS> the shape <S>. Writes the orientation, the index of the TShape and the index of the Location.", py::arg("S"), py::arg("OS"));
cls_TopTools_ShapeSet.def("Read", (void (TopTools_ShapeSet::*)(TopoDS_Shape &, Standard_IStream &) const) &TopTools_ShapeSet::Read, "Reads from <IS> a shape and returns it in S.", py::arg("S"), py::arg("IS"));
cls_TopTools_ShapeSet.def("AddGeometry", (void (TopTools_ShapeSet::*)(const TopoDS_Shape &)) &TopTools_ShapeSet::AddGeometry, "Stores the geometry of <S>.", py::arg("S"));
cls_TopTools_ShapeSet.def("DumpGeometry", (void (TopTools_ShapeSet::*)(Standard_OStream &) const) &TopTools_ShapeSet::DumpGeometry, "Dumps the geometry of me on the stream <OS>.", py::arg("OS"));
cls_TopTools_ShapeSet.def("WriteGeometry", (void (TopTools_ShapeSet::*)(Standard_OStream &)) &TopTools_ShapeSet::WriteGeometry, "Writes the geometry of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
cls_TopTools_ShapeSet.def("ReadGeometry", (void (TopTools_ShapeSet::*)(Standard_IStream &)) &TopTools_ShapeSet::ReadGeometry, "Reads the geometry of me from the stream <IS>.", py::arg("IS"));
cls_TopTools_ShapeSet.def("DumpGeometry", (void (TopTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const) &TopTools_ShapeSet::DumpGeometry, "Dumps the geometry of <S> on the stream <OS>.", py::arg("S"), py::arg("OS"));
cls_TopTools_ShapeSet.def("WriteGeometry", (void (TopTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const) &TopTools_ShapeSet::WriteGeometry, "Writes the geometry of <S> on the stream <OS> in a format that can be read back by Read.", py::arg("S"), py::arg("OS"));
cls_TopTools_ShapeSet.def("ReadGeometry", (void (TopTools_ShapeSet::*)(const TopAbs_ShapeEnum, Standard_IStream &, TopoDS_Shape &)) &TopTools_ShapeSet::ReadGeometry, "Reads the geometry of a shape of type <T> from the stream <IS> and returns it in <S>.", py::arg("T"), py::arg("IS"), py::arg("S"));
cls_TopTools_ShapeSet.def("AddShapes", (void (TopTools_ShapeSet::*)(TopoDS_Shape &, const TopoDS_Shape &)) &TopTools_ShapeSet::AddShapes, "Inserts the shape <S2> in the shape <S1>. This method must be redefined to use the correct builder.", py::arg("S1"), py::arg("S2"));
cls_TopTools_ShapeSet.def("Check", (void (TopTools_ShapeSet::*)(const TopAbs_ShapeEnum, TopoDS_Shape &)) &TopTools_ShapeSet::Check, "This method is called after each new completed shape. <T> is the type. <S> is the shape. In this class it does nothing, but it gives the opportunity in derived classes to perform extra treatment on shapes.", py::arg("T"), py::arg("S"));
cls_TopTools_ShapeSet.def("NbShapes", (Standard_Integer (TopTools_ShapeSet::*)() const) &TopTools_ShapeSet::NbShapes, "Returns number of shapes read from file.");
cls_TopTools_ShapeSet.def("SetProgress", (void (TopTools_ShapeSet::*)(const opencascade::handle<Message_ProgressIndicator> &)) &TopTools_ShapeSet::SetProgress, "None", py::arg("PR"));
cls_TopTools_ShapeSet.def("GetProgress", (opencascade::handle<Message_ProgressIndicator> (TopTools_ShapeSet::*)() const) &TopTools_ShapeSet::GetProgress, "None");

// Enums

}
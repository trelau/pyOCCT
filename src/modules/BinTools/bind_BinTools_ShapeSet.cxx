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
#include <BinTools_LocationSet.hxx>
#include <Standard_OStream.hxx>
#include <Standard_IStream.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <BRep_Builder.hxx>
#include <BinTools_SurfaceSet.hxx>
#include <BinTools_CurveSet.hxx>
#include <BinTools_Curve2dSet.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <BinTools_ShapeSet.hxx>

void bind_BinTools_ShapeSet(py::module &mod){

py::class_<BinTools_ShapeSet, std::unique_ptr<BinTools_ShapeSet, Deleter<BinTools_ShapeSet>>> cls_BinTools_ShapeSet(mod, "BinTools_ShapeSet", "Writes topology in OStream in binary format");

// Constructors
cls_BinTools_ShapeSet.def(py::init<>());
cls_BinTools_ShapeSet.def(py::init<const Standard_Boolean>(), py::arg("isWithTriangles"));

// Fields

// Methods
// cls_BinTools_ShapeSet.def_static("operator new_", (void * (*)(size_t)) &BinTools_ShapeSet::operator new, "None", py::arg("theSize"));
// cls_BinTools_ShapeSet.def_static("operator delete_", (void (*)(void *)) &BinTools_ShapeSet::operator delete, "None", py::arg("theAddress"));
// cls_BinTools_ShapeSet.def_static("operator new[]_", (void * (*)(size_t)) &BinTools_ShapeSet::operator new[], "None", py::arg("theSize"));
// cls_BinTools_ShapeSet.def_static("operator delete[]_", (void (*)(void *)) &BinTools_ShapeSet::operator delete[], "None", py::arg("theAddress"));
// cls_BinTools_ShapeSet.def_static("operator new_", (void * (*)(size_t, void *)) &BinTools_ShapeSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BinTools_ShapeSet.def_static("operator delete_", (void (*)(void *, void *)) &BinTools_ShapeSet::operator delete, "None", py::arg(""), py::arg(""));
cls_BinTools_ShapeSet.def("IsWithTriangles", (Standard_Boolean (BinTools_ShapeSet::*)() const) &BinTools_ShapeSet::IsWithTriangles, "Return true if shape should be stored with triangles.");
cls_BinTools_ShapeSet.def("SetWithTriangles", (void (BinTools_ShapeSet::*)(const Standard_Boolean)) &BinTools_ShapeSet::SetWithTriangles, "Define if shape will be stored with triangles. Ignored (always written) if face defines only triangulation (no surface).", py::arg("isWithTriangles"));
cls_BinTools_ShapeSet.def("SetFormatNb", (void (BinTools_ShapeSet::*)(const Standard_Integer)) &BinTools_ShapeSet::SetFormatNb, "None", py::arg("theFormatNb"));
cls_BinTools_ShapeSet.def("FormatNb", (Standard_Integer (BinTools_ShapeSet::*)() const) &BinTools_ShapeSet::FormatNb, "two formats available for the moment: First: does not write CurveOnSurface UV Points into the file on reading calls Check() method. Second: stores CurveOnSurface UV Points. On reading format is recognized from Version string.");
cls_BinTools_ShapeSet.def("Clear", (void (BinTools_ShapeSet::*)()) &BinTools_ShapeSet::Clear, "Clears the content of the set.");
cls_BinTools_ShapeSet.def("Add", (Standard_Integer (BinTools_ShapeSet::*)(const TopoDS_Shape &)) &BinTools_ShapeSet::Add, "Stores <S> and its sub-shape. Returns the index of <S>. The method AddGeometry is called on each sub-shape.", py::arg("S"));
cls_BinTools_ShapeSet.def("Shape", (const TopoDS_Shape & (BinTools_ShapeSet::*)(const Standard_Integer) const) &BinTools_ShapeSet::Shape, "Returns the sub-shape of index <I>.", py::arg("I"));
cls_BinTools_ShapeSet.def("Index", (Standard_Integer (BinTools_ShapeSet::*)(const TopoDS_Shape &) const) &BinTools_ShapeSet::Index, "Returns the index of <S>.", py::arg("S"));
cls_BinTools_ShapeSet.def("Locations", (const BinTools_LocationSet & (BinTools_ShapeSet::*)() const) &BinTools_ShapeSet::Locations, "None");
cls_BinTools_ShapeSet.def("ChangeLocations", (BinTools_LocationSet & (BinTools_ShapeSet::*)()) &BinTools_ShapeSet::ChangeLocations, "None");
cls_BinTools_ShapeSet.def("NbShapes", (Standard_Integer (BinTools_ShapeSet::*)() const) &BinTools_ShapeSet::NbShapes, "Returns number of shapes read from file.");
cls_BinTools_ShapeSet.def("Write", (void (BinTools_ShapeSet::*)(Standard_OStream &) const) &BinTools_ShapeSet::Write, "Writes the content of me on the stream <OS> in binary format that can be read back by Read.", py::arg("OS"));
cls_BinTools_ShapeSet.def("Read", (void (BinTools_ShapeSet::*)(Standard_IStream &)) &BinTools_ShapeSet::Read, "Reads the content of me from the binary stream <IS>. me is first cleared.", py::arg("IS"));
cls_BinTools_ShapeSet.def("Write", (void (BinTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const) &BinTools_ShapeSet::Write, "Writes on <OS> the shape <S>. Writes the orientation, the index of the TShape and the index of the Location.", py::arg("S"), py::arg("OS"));
cls_BinTools_ShapeSet.def("WriteGeometry", (void (BinTools_ShapeSet::*)(Standard_OStream &) const) &BinTools_ShapeSet::WriteGeometry, "Writes the geometry of me on the stream <OS> in a binary format that can be read back by Read.", py::arg("OS"));
cls_BinTools_ShapeSet.def("ReadGeometry", (void (BinTools_ShapeSet::*)(Standard_IStream &)) &BinTools_ShapeSet::ReadGeometry, "Reads the geometry of me from the stream <IS>.", py::arg("IS"));
cls_BinTools_ShapeSet.def("Read", (void (BinTools_ShapeSet::*)(TopoDS_Shape &, Standard_IStream &, const Standard_Integer) const) &BinTools_ShapeSet::Read, "Reads from <IS> a shape and returns it in S. <NbShapes> is the number of tshapes in the set.", py::arg("S"), py::arg("IS"), py::arg("NbShapes"));
cls_BinTools_ShapeSet.def("WriteGeometry", (void (BinTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const) &BinTools_ShapeSet::WriteGeometry, "Writes the geometry of <S> on the stream <OS> in a binary format that can be read back by Read.", py::arg("S"), py::arg("OS"));
cls_BinTools_ShapeSet.def("ReadGeometry", (void (BinTools_ShapeSet::*)(const TopAbs_ShapeEnum, Standard_IStream &, TopoDS_Shape &)) &BinTools_ShapeSet::ReadGeometry, "Reads the geometry of a shape of type <T> from the stream <IS> and returns it in <S>.", py::arg("T"), py::arg("IS"), py::arg("S"));
cls_BinTools_ShapeSet.def("AddGeometry", (void (BinTools_ShapeSet::*)(const TopoDS_Shape &)) &BinTools_ShapeSet::AddGeometry, "Stores the goemetry of <S>.", py::arg("S"));
cls_BinTools_ShapeSet.def("AddShapes", (void (BinTools_ShapeSet::*)(TopoDS_Shape &, const TopoDS_Shape &)) &BinTools_ShapeSet::AddShapes, "Inserts the shape <S2> in the shape <S1>.", py::arg("S1"), py::arg("S2"));
cls_BinTools_ShapeSet.def("ReadPolygon3D", (void (BinTools_ShapeSet::*)(Standard_IStream &)) &BinTools_ShapeSet::ReadPolygon3D, "Reads the 3d polygons of me from the stream <IS>.", py::arg("IS"));
cls_BinTools_ShapeSet.def("WritePolygon3D", (void (BinTools_ShapeSet::*)(Standard_OStream &) const) &BinTools_ShapeSet::WritePolygon3D, "Writes the 3d polygons on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
cls_BinTools_ShapeSet.def("ReadTriangulation", (void (BinTools_ShapeSet::*)(Standard_IStream &)) &BinTools_ShapeSet::ReadTriangulation, "Reads the triangulation of me from the stream <IS>.", py::arg("IS"));
cls_BinTools_ShapeSet.def("WriteTriangulation", (void (BinTools_ShapeSet::*)(Standard_OStream &) const) &BinTools_ShapeSet::WriteTriangulation, "Writes the triangulation on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
cls_BinTools_ShapeSet.def("ReadPolygonOnTriangulation", (void (BinTools_ShapeSet::*)(Standard_IStream &)) &BinTools_ShapeSet::ReadPolygonOnTriangulation, "Reads the polygons on triangulation of me from the stream <IS>.", py::arg("IS"));
cls_BinTools_ShapeSet.def("WritePolygonOnTriangulation", (void (BinTools_ShapeSet::*)(Standard_OStream &) const) &BinTools_ShapeSet::WritePolygonOnTriangulation, "Writes the polygons on triangulation on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));

// Enums

}
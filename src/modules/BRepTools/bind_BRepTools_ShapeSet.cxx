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
#include <TopTools_ShapeSet.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <BRep_Builder.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_OStream.hxx>
#include <Standard_IStream.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <GeomTools_SurfaceSet.hxx>
#include <GeomTools_CurveSet.hxx>
#include <GeomTools_Curve2dSet.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <BRepTools_ShapeSet.hxx>

void bind_BRepTools_ShapeSet(py::module &mod){

py::class_<BRepTools_ShapeSet, TopTools_ShapeSet> cls_BRepTools_ShapeSet(mod, "BRepTools_ShapeSet", "Contains a Shape and all its subshapes, locations and geometries.");

// Constructors
cls_BRepTools_ShapeSet.def(py::init<>());
cls_BRepTools_ShapeSet.def(py::init<const Standard_Boolean>(), py::arg("isWithTriangles"));
cls_BRepTools_ShapeSet.def(py::init<const BRep_Builder &>(), py::arg("B"));
cls_BRepTools_ShapeSet.def(py::init<const BRep_Builder &, const Standard_Boolean>(), py::arg("B"), py::arg("isWithTriangles"));

// Fields

// Methods
// cls_BRepTools_ShapeSet.def_static("operator new_", (void * (*)(size_t)) &BRepTools_ShapeSet::operator new, "None", py::arg("theSize"));
// cls_BRepTools_ShapeSet.def_static("operator delete_", (void (*)(void *)) &BRepTools_ShapeSet::operator delete, "None", py::arg("theAddress"));
// cls_BRepTools_ShapeSet.def_static("operator new[]_", (void * (*)(size_t)) &BRepTools_ShapeSet::operator new[], "None", py::arg("theSize"));
// cls_BRepTools_ShapeSet.def_static("operator delete[]_", (void (*)(void *)) &BRepTools_ShapeSet::operator delete[], "None", py::arg("theAddress"));
// cls_BRepTools_ShapeSet.def_static("operator new_", (void * (*)(size_t, void *)) &BRepTools_ShapeSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepTools_ShapeSet.def_static("operator delete_", (void (*)(void *, void *)) &BRepTools_ShapeSet::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepTools_ShapeSet.def("Clear", (void (BRepTools_ShapeSet::*)()) &BRepTools_ShapeSet::Clear, "Clears the content of the set.");
cls_BRepTools_ShapeSet.def("AddGeometry", (void (BRepTools_ShapeSet::*)(const TopoDS_Shape &)) &BRepTools_ShapeSet::AddGeometry, "Stores the goemetry of <S>.", py::arg("S"));
cls_BRepTools_ShapeSet.def("DumpGeometry", (void (BRepTools_ShapeSet::*)(Standard_OStream &) const) &BRepTools_ShapeSet::DumpGeometry, "Dumps the geometry of me on the stream <OS>.", py::arg("OS"));
cls_BRepTools_ShapeSet.def("WriteGeometry", (void (BRepTools_ShapeSet::*)(Standard_OStream &)) &BRepTools_ShapeSet::WriteGeometry, "Writes the geometry of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
cls_BRepTools_ShapeSet.def("ReadGeometry", (void (BRepTools_ShapeSet::*)(Standard_IStream &)) &BRepTools_ShapeSet::ReadGeometry, "Reads the geometry of me from the stream <IS>.", py::arg("IS"));
cls_BRepTools_ShapeSet.def("DumpGeometry", (void (BRepTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const) &BRepTools_ShapeSet::DumpGeometry, "Dumps the geometry of <S> on the stream <OS>.", py::arg("S"), py::arg("OS"));
cls_BRepTools_ShapeSet.def("WriteGeometry", (void (BRepTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const) &BRepTools_ShapeSet::WriteGeometry, "Writes the geometry of <S> on the stream <OS> in a format that can be read back by Read.", py::arg("S"), py::arg("OS"));
cls_BRepTools_ShapeSet.def("ReadGeometry", (void (BRepTools_ShapeSet::*)(const TopAbs_ShapeEnum, Standard_IStream &, TopoDS_Shape &)) &BRepTools_ShapeSet::ReadGeometry, "Reads the geometry of a shape of type <T> from the stream <IS> and returns it in <S>.", py::arg("T"), py::arg("IS"), py::arg("S"));
cls_BRepTools_ShapeSet.def("AddShapes", (void (BRepTools_ShapeSet::*)(TopoDS_Shape &, const TopoDS_Shape &)) &BRepTools_ShapeSet::AddShapes, "Inserts the shape <S2> in the shape <S1>. This method must be redefined to use the correct builder.", py::arg("S1"), py::arg("S2"));
cls_BRepTools_ShapeSet.def("Check", (void (BRepTools_ShapeSet::*)(const TopAbs_ShapeEnum, TopoDS_Shape &)) &BRepTools_ShapeSet::Check, "None", py::arg("T"), py::arg("S"));
cls_BRepTools_ShapeSet.def("ReadPolygon3D", (void (BRepTools_ShapeSet::*)(Standard_IStream &)) &BRepTools_ShapeSet::ReadPolygon3D, "Reads the 3d polygons of me from the stream <IS>.", py::arg("IS"));
cls_BRepTools_ShapeSet.def("WritePolygon3D", [](BRepTools_ShapeSet &self, Standard_OStream & a0) -> void { return self.WritePolygon3D(a0); });
cls_BRepTools_ShapeSet.def("WritePolygon3D", (void (BRepTools_ShapeSet::*)(Standard_OStream &, const Standard_Boolean) const) &BRepTools_ShapeSet::WritePolygon3D, "Writes the 3d polygons on the stream <OS> in a format that can be read back by Read.", py::arg("OS"), py::arg("Compact"));
cls_BRepTools_ShapeSet.def("DumpPolygon3D", (void (BRepTools_ShapeSet::*)(Standard_OStream &) const) &BRepTools_ShapeSet::DumpPolygon3D, "Dumps the 3d polygons on the stream <OS>.", py::arg("OS"));
cls_BRepTools_ShapeSet.def("ReadTriangulation", (void (BRepTools_ShapeSet::*)(Standard_IStream &)) &BRepTools_ShapeSet::ReadTriangulation, "Reads the triangulation of me from the stream <IS>.", py::arg("IS"));
cls_BRepTools_ShapeSet.def("WriteTriangulation", [](BRepTools_ShapeSet &self, Standard_OStream & a0) -> void { return self.WriteTriangulation(a0); });
cls_BRepTools_ShapeSet.def("WriteTriangulation", (void (BRepTools_ShapeSet::*)(Standard_OStream &, const Standard_Boolean) const) &BRepTools_ShapeSet::WriteTriangulation, "Writes the triangulation on the stream <OS> in a format that can be read back by Read.", py::arg("OS"), py::arg("Compact"));
cls_BRepTools_ShapeSet.def("DumpTriangulation", (void (BRepTools_ShapeSet::*)(Standard_OStream &) const) &BRepTools_ShapeSet::DumpTriangulation, "Dumps the triangulation on the stream <OS>.", py::arg("OS"));
cls_BRepTools_ShapeSet.def("ReadPolygonOnTriangulation", (void (BRepTools_ShapeSet::*)(Standard_IStream &)) &BRepTools_ShapeSet::ReadPolygonOnTriangulation, "Reads the polygons on triangulation of me from the stream <IS>.", py::arg("IS"));
cls_BRepTools_ShapeSet.def("WritePolygonOnTriangulation", [](BRepTools_ShapeSet &self, Standard_OStream & a0) -> void { return self.WritePolygonOnTriangulation(a0); });
cls_BRepTools_ShapeSet.def("WritePolygonOnTriangulation", (void (BRepTools_ShapeSet::*)(Standard_OStream &, const Standard_Boolean) const) &BRepTools_ShapeSet::WritePolygonOnTriangulation, "Writes the polygons on triangulation on the stream <OS> in a format that can be read back by Read.", py::arg("OS"), py::arg("Compact"));
cls_BRepTools_ShapeSet.def("DumpPolygonOnTriangulation", (void (BRepTools_ShapeSet::*)(Standard_OStream &) const) &BRepTools_ShapeSet::DumpPolygonOnTriangulation, "Dumps the polygons on triangulation on the stream <OS>.", py::arg("OS"));

// Enums

}
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
#include <ChFi3d_FilBuilder.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <ChFi3d_FilletShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <TopoDS_Face.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <FilletSurf_StatusType.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <ChFiDS_SequenceOfSurfData.hxx>
#include <ChFiDS_HElSpine.hxx>
#include <ChFiDS_Spine.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <math_Vector.hxx>
#include <BRepAdaptor_HCurve2d.hxx>
#include <TopAbs_Orientation.hxx>
#include <FilletSurf_InternalBuilder.hxx>

void bind_FilletSurf_InternalBuilder(py::module &mod){

py::class_<FilletSurf_InternalBuilder, std::unique_ptr<FilletSurf_InternalBuilder, Deleter<FilletSurf_InternalBuilder>>, ChFi3d_FilBuilder> cls_FilletSurf_InternalBuilder(mod, "FilletSurf_InternalBuilder", "This class is private. It is used by the class Builder from FilletSurf. It computes geometric information about fillets.");

// Constructors
cls_FilletSurf_InternalBuilder.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_FilletSurf_InternalBuilder.def(py::init<const TopoDS_Shape &, const ChFi3d_FilletShape>(), py::arg("S"), py::arg("FShape"));
cls_FilletSurf_InternalBuilder.def(py::init<const TopoDS_Shape &, const ChFi3d_FilletShape, const Standard_Real>(), py::arg("S"), py::arg("FShape"), py::arg("Ta"));
cls_FilletSurf_InternalBuilder.def(py::init<const TopoDS_Shape &, const ChFi3d_FilletShape, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("FShape"), py::arg("Ta"), py::arg("Tapp3d"));
cls_FilletSurf_InternalBuilder.def(py::init<const TopoDS_Shape &, const ChFi3d_FilletShape, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("FShape"), py::arg("Ta"), py::arg("Tapp3d"), py::arg("Tapp2d"));

// Fields

// Methods
// cls_FilletSurf_InternalBuilder.def_static("operator new_", (void * (*)(size_t)) &FilletSurf_InternalBuilder::operator new, "None", py::arg("theSize"));
// cls_FilletSurf_InternalBuilder.def_static("operator delete_", (void (*)(void *)) &FilletSurf_InternalBuilder::operator delete, "None", py::arg("theAddress"));
// cls_FilletSurf_InternalBuilder.def_static("operator new[]_", (void * (*)(size_t)) &FilletSurf_InternalBuilder::operator new[], "None", py::arg("theSize"));
// cls_FilletSurf_InternalBuilder.def_static("operator delete[]_", (void (*)(void *)) &FilletSurf_InternalBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_FilletSurf_InternalBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &FilletSurf_InternalBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_FilletSurf_InternalBuilder.def_static("operator delete_", (void (*)(void *, void *)) &FilletSurf_InternalBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_FilletSurf_InternalBuilder.def("Add", (Standard_Integer (FilletSurf_InternalBuilder::*)(const TopTools_ListOfShape &, const Standard_Real)) &FilletSurf_InternalBuilder::Add, "Initializes the contour with a list of Edges 0 : no problem 1 : empty list 2 : the edges are not G1 3 : two connected faces on a same support are not G1 4 : the edge is not on shape 5 : NotSharpEdge: the edge is not sharp", py::arg("E"), py::arg("R"));
cls_FilletSurf_InternalBuilder.def("Perform", (void (FilletSurf_InternalBuilder::*)()) &FilletSurf_InternalBuilder::Perform, "None");
cls_FilletSurf_InternalBuilder.def("Done", (Standard_Boolean (FilletSurf_InternalBuilder::*)() const) &FilletSurf_InternalBuilder::Done, "None");
cls_FilletSurf_InternalBuilder.def("NbSurface", (Standard_Integer (FilletSurf_InternalBuilder::*)() const) &FilletSurf_InternalBuilder::NbSurface, "gives the number of NUBS surfaces of the Fillet.");
cls_FilletSurf_InternalBuilder.def("SurfaceFillet", (const opencascade::handle<Geom_Surface> & (FilletSurf_InternalBuilder::*)(const Standard_Integer) const) &FilletSurf_InternalBuilder::SurfaceFillet, "gives the NUBS surface of index Index.", py::arg("Index"));
cls_FilletSurf_InternalBuilder.def("TolApp3d", (Standard_Real (FilletSurf_InternalBuilder::*)(const Standard_Integer) const) &FilletSurf_InternalBuilder::TolApp3d, "gives the 3d tolerance reached during approximation of the surface of index Index", py::arg("Index"));
cls_FilletSurf_InternalBuilder.def("SupportFace1", (const TopoDS_Face & (FilletSurf_InternalBuilder::*)(const Standard_Integer) const) &FilletSurf_InternalBuilder::SupportFace1, "gives the first support face relative to SurfaceFillet(Index);", py::arg("Index"));
cls_FilletSurf_InternalBuilder.def("SupportFace2", (const TopoDS_Face & (FilletSurf_InternalBuilder::*)(const Standard_Integer) const) &FilletSurf_InternalBuilder::SupportFace2, "gives the second support face relative to SurfaceFillet(Index);", py::arg("Index"));
cls_FilletSurf_InternalBuilder.def("CurveOnFace1", (const opencascade::handle<Geom_Curve> & (FilletSurf_InternalBuilder::*)(const Standard_Integer) const) &FilletSurf_InternalBuilder::CurveOnFace1, "gives the 3d curve of SurfaceFillet(Index) on SupportFace1(Index)", py::arg("Index"));
cls_FilletSurf_InternalBuilder.def("CurveOnFace2", (const opencascade::handle<Geom_Curve> & (FilletSurf_InternalBuilder::*)(const Standard_Integer) const) &FilletSurf_InternalBuilder::CurveOnFace2, "gives the 3d curve of SurfaceFillet(Index) on SupportFace2(Index)", py::arg("Index"));
cls_FilletSurf_InternalBuilder.def("PCurveOnFace1", (const opencascade::handle<Geom2d_Curve> & (FilletSurf_InternalBuilder::*)(const Standard_Integer) const) &FilletSurf_InternalBuilder::PCurveOnFace1, "gives the PCurve associated to CurvOnSup1(Index) on the support face", py::arg("Index"));
cls_FilletSurf_InternalBuilder.def("PCurve1OnFillet", (const opencascade::handle<Geom2d_Curve> & (FilletSurf_InternalBuilder::*)(const Standard_Integer) const) &FilletSurf_InternalBuilder::PCurve1OnFillet, "gives the PCurve associated to CurveOnFace1(Index) on the Fillet", py::arg("Index"));
cls_FilletSurf_InternalBuilder.def("PCurveOnFace2", (const opencascade::handle<Geom2d_Curve> & (FilletSurf_InternalBuilder::*)(const Standard_Integer) const) &FilletSurf_InternalBuilder::PCurveOnFace2, "gives the PCurve associated to CurveOnSup2(Index) on the support face", py::arg("Index"));
cls_FilletSurf_InternalBuilder.def("PCurve2OnFillet", (const opencascade::handle<Geom2d_Curve> & (FilletSurf_InternalBuilder::*)(const Standard_Integer) const) &FilletSurf_InternalBuilder::PCurve2OnFillet, "gives the PCurve associated to CurveOnSup2(Index) on the fillet", py::arg("Index"));
cls_FilletSurf_InternalBuilder.def("FirstParameter", (Standard_Real (FilletSurf_InternalBuilder::*)() const) &FilletSurf_InternalBuilder::FirstParameter, "gives the parameter of the fillet on the first edge.");
cls_FilletSurf_InternalBuilder.def("LastParameter", (Standard_Real (FilletSurf_InternalBuilder::*)() const) &FilletSurf_InternalBuilder::LastParameter, "gives the parameter of the fillet on the last edge");
cls_FilletSurf_InternalBuilder.def("StartSectionStatus", (FilletSurf_StatusType (FilletSurf_InternalBuilder::*)() const) &FilletSurf_InternalBuilder::StartSectionStatus, "None");
cls_FilletSurf_InternalBuilder.def("EndSectionStatus", (FilletSurf_StatusType (FilletSurf_InternalBuilder::*)() const) &FilletSurf_InternalBuilder::EndSectionStatus, "None");
cls_FilletSurf_InternalBuilder.def("Simulate", (void (FilletSurf_InternalBuilder::*)()) &FilletSurf_InternalBuilder::Simulate, "None");
cls_FilletSurf_InternalBuilder.def("NbSection", (Standard_Integer (FilletSurf_InternalBuilder::*)(const Standard_Integer) const) &FilletSurf_InternalBuilder::NbSection, "None", py::arg("IndexSurf"));
cls_FilletSurf_InternalBuilder.def("Section", (void (FilletSurf_InternalBuilder::*)(const Standard_Integer, const Standard_Integer, opencascade::handle<Geom_TrimmedCurve> &) const) &FilletSurf_InternalBuilder::Section, "None", py::arg("IndexSurf"), py::arg("IndexSec"), py::arg("Circ"));

// Enums

}
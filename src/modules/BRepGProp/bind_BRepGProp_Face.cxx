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
#include <TopoDS_Face.hxx>
#include <gp_Pnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <TopoDS_Edge.hxx>
#include <gp_Vec2d.hxx>
#include <GeomAbs_IsoType.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <BRepGProp_Face.hxx>

void bind_BRepGProp_Face(py::module &mod){

py::class_<BRepGProp_Face, std::unique_ptr<BRepGProp_Face, Deleter<BRepGProp_Face>>> cls_BRepGProp_Face(mod, "BRepGProp_Face", "None");

// Constructors
cls_BRepGProp_Face.def(py::init<>());
cls_BRepGProp_Face.def(py::init<const Standard_Boolean>(), py::arg("IsUseSpan"));
cls_BRepGProp_Face.def(py::init<const TopoDS_Face &>(), py::arg("F"));
cls_BRepGProp_Face.def(py::init<const TopoDS_Face &, const Standard_Boolean>(), py::arg("F"), py::arg("IsUseSpan"));

// Fields

// Methods
// cls_BRepGProp_Face.def_static("operator new_", (void * (*)(size_t)) &BRepGProp_Face::operator new, "None", py::arg("theSize"));
// cls_BRepGProp_Face.def_static("operator delete_", (void (*)(void *)) &BRepGProp_Face::operator delete, "None", py::arg("theAddress"));
// cls_BRepGProp_Face.def_static("operator new[]_", (void * (*)(size_t)) &BRepGProp_Face::operator new[], "None", py::arg("theSize"));
// cls_BRepGProp_Face.def_static("operator delete[]_", (void (*)(void *)) &BRepGProp_Face::operator delete[], "None", py::arg("theAddress"));
// cls_BRepGProp_Face.def_static("operator new_", (void * (*)(size_t, void *)) &BRepGProp_Face::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepGProp_Face.def_static("operator delete_", (void (*)(void *, void *)) &BRepGProp_Face::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepGProp_Face.def("Load", (void (BRepGProp_Face::*)(const TopoDS_Face &)) &BRepGProp_Face::Load, "None", py::arg("F"));
cls_BRepGProp_Face.def("VIntegrationOrder", (Standard_Integer (BRepGProp_Face::*)() const) &BRepGProp_Face::VIntegrationOrder, "None");
cls_BRepGProp_Face.def("NaturalRestriction", (Standard_Boolean (BRepGProp_Face::*)() const) &BRepGProp_Face::NaturalRestriction, "Returns Standard_True if the face is not trimmed.");
cls_BRepGProp_Face.def("GetFace", (const TopoDS_Face & (BRepGProp_Face::*)() const) &BRepGProp_Face::GetFace, "Returns the TopoDS face.");
cls_BRepGProp_Face.def("Value2d", (gp_Pnt2d (BRepGProp_Face::*)(const Standard_Real) const) &BRepGProp_Face::Value2d, "Returns the value of the boundary curve of the face.", py::arg("U"));
cls_BRepGProp_Face.def("SIntOrder", (Standard_Integer (BRepGProp_Face::*)(const Standard_Real) const) &BRepGProp_Face::SIntOrder, "None", py::arg("Eps"));
cls_BRepGProp_Face.def("SVIntSubs", (Standard_Integer (BRepGProp_Face::*)() const) &BRepGProp_Face::SVIntSubs, "None");
cls_BRepGProp_Face.def("SUIntSubs", (Standard_Integer (BRepGProp_Face::*)() const) &BRepGProp_Face::SUIntSubs, "None");
cls_BRepGProp_Face.def("UKnots", (void (BRepGProp_Face::*)(TColStd_Array1OfReal &) const) &BRepGProp_Face::UKnots, "None", py::arg("Knots"));
cls_BRepGProp_Face.def("VKnots", (void (BRepGProp_Face::*)(TColStd_Array1OfReal &) const) &BRepGProp_Face::VKnots, "None", py::arg("Knots"));
cls_BRepGProp_Face.def("LIntOrder", (Standard_Integer (BRepGProp_Face::*)(const Standard_Real) const) &BRepGProp_Face::LIntOrder, "None", py::arg("Eps"));
cls_BRepGProp_Face.def("LIntSubs", (Standard_Integer (BRepGProp_Face::*)() const) &BRepGProp_Face::LIntSubs, "None");
cls_BRepGProp_Face.def("LKnots", (void (BRepGProp_Face::*)(TColStd_Array1OfReal &) const) &BRepGProp_Face::LKnots, "None", py::arg("Knots"));
cls_BRepGProp_Face.def("UIntegrationOrder", (Standard_Integer (BRepGProp_Face::*)() const) &BRepGProp_Face::UIntegrationOrder, "Returns the number of points required to do the integration in the U parametric direction with a good accuracy.");
cls_BRepGProp_Face.def("Bounds", [](BRepGProp_Face &self, Standard_Real & U1, Standard_Real & U2, Standard_Real & V1, Standard_Real & V2){ self.Bounds(U1, U2, V1, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, U2, V1, V2); }, "Returns the parametric bounds of the Face.", py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_BRepGProp_Face.def("Normal", (void (BRepGProp_Face::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &) const) &BRepGProp_Face::Normal, "Computes the point of parameter U, V on the Face <S> and the normal to the face at this point.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("VNor"));
cls_BRepGProp_Face.def("Load", (void (BRepGProp_Face::*)(const TopoDS_Edge &)) &BRepGProp_Face::Load, "Loading the boundary arc.", py::arg("E"));
cls_BRepGProp_Face.def("FirstParameter", (Standard_Real (BRepGProp_Face::*)() const) &BRepGProp_Face::FirstParameter, "Returns the parametric value of the start point of the current arc of curve.");
cls_BRepGProp_Face.def("LastParameter", (Standard_Real (BRepGProp_Face::*)() const) &BRepGProp_Face::LastParameter, "Returns the parametric value of the end point of the current arc of curve.");
cls_BRepGProp_Face.def("IntegrationOrder", (Standard_Integer (BRepGProp_Face::*)() const) &BRepGProp_Face::IntegrationOrder, "Returns the number of points required to do the integration along the parameter of curve.");
cls_BRepGProp_Face.def("D12d", (void (BRepGProp_Face::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &BRepGProp_Face::D12d, "Returns the point of parameter U and the first derivative at this point of a boundary curve.", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_BRepGProp_Face.def("Load", (void (BRepGProp_Face::*)(const Standard_Boolean, const GeomAbs_IsoType)) &BRepGProp_Face::Load, "Loading the boundary arc. This arc is either a top, bottom, left or right bound of a UV rectangle in which the parameters of surface are defined. If IsFirstParam is equal to Standard_True, the face is initialized by either left of bottom bound. Otherwise it is initialized by the top or right one. If theIsoType is equal to GeomAbs_IsoU, the face is initialized with either left or right bound. Otherwise - with either top or bottom one.", py::arg("IsFirstParam"), py::arg("theIsoType"));
cls_BRepGProp_Face.def("GetUKnots", (void (BRepGProp_Face::*)(const Standard_Real, const Standard_Real, opencascade::handle<TColStd_HArray1OfReal> &) const) &BRepGProp_Face::GetUKnots, "Returns an array of U knots of the face. The first and last elements of the array will be theUMin and theUMax. The middle elements will be the U Knots of the face greater then theUMin and lower then theUMax in increasing order. If the face is not a BSpline, the array initialized with theUMin and theUMax only.", py::arg("theUMin"), py::arg("theUMax"), py::arg("theUKnots"));
cls_BRepGProp_Face.def("GetTKnots", (void (BRepGProp_Face::*)(const Standard_Real, const Standard_Real, opencascade::handle<TColStd_HArray1OfReal> &) const) &BRepGProp_Face::GetTKnots, "Returns an array of combination of T knots of the arc and V knots of the face. The first and last elements of the array will be theTMin and theTMax. The middle elements will be the Knots of the arc and the values of parameters of arc on which the value points have V coordinates close to V knots of face. All the parameter will be greater then theTMin and lower then theTMax in increasing order. If the face is not a BSpline, the array initialized with theTMin and theTMax only.", py::arg("theTMin"), py::arg("theTMax"), py::arg("theTKnots"));

// Enums

}
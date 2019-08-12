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
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom2d_Curve.hxx>
#include <GeomLProp_SLProps.hxx>
#include <LocalAnalysis_StatusErrorType.hxx>
#include <LocalAnalysis_SurfaceContinuity.hxx>

void bind_LocalAnalysis_SurfaceContinuity(py::module &mod){

py::class_<LocalAnalysis_SurfaceContinuity, std::unique_ptr<LocalAnalysis_SurfaceContinuity, Deleter<LocalAnalysis_SurfaceContinuity>>> cls_LocalAnalysis_SurfaceContinuity(mod, "LocalAnalysis_SurfaceContinuity", "This class gives tools to check local continuity C0 C1 C2 G1 G2 between two points situated on two surfaces");

// Constructors
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape>(), py::arg("Surf1"), py::arg("u1"), py::arg("v1"), py::arg("Surf2"), py::arg("u2"), py::arg("v2"), py::arg("Order"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Real>(), py::arg("Surf1"), py::arg("u1"), py::arg("v1"), py::arg("Surf2"), py::arg("u2"), py::arg("v2"), py::arg("Order"), py::arg("EpsNul"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real>(), py::arg("Surf1"), py::arg("u1"), py::arg("v1"), py::arg("Surf2"), py::arg("u2"), py::arg("v2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surf1"), py::arg("u1"), py::arg("v1"), py::arg("Surf2"), py::arg("u2"), py::arg("v2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surf1"), py::arg("u1"), py::arg("v1"), py::arg("Surf2"), py::arg("u2"), py::arg("v2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surf1"), py::arg("u1"), py::arg("v1"), py::arg("Surf2"), py::arg("u2"), py::arg("v2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surf1"), py::arg("u1"), py::arg("v1"), py::arg("Surf2"), py::arg("u2"), py::arg("v2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"), py::arg("Percent"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surf1"), py::arg("u1"), py::arg("v1"), py::arg("Surf2"), py::arg("u2"), py::arg("v2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"), py::arg("Percent"), py::arg("Maxlen"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const GeomAbs_Shape>(), py::arg("curv1"), py::arg("curv2"), py::arg("U"), py::arg("Surf1"), py::arg("Surf2"), py::arg("Order"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const GeomAbs_Shape, const Standard_Real>(), py::arg("curv1"), py::arg("curv2"), py::arg("U"), py::arg("Surf1"), py::arg("Surf2"), py::arg("Order"), py::arg("EpsNul"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const GeomAbs_Shape, const Standard_Real, const Standard_Real>(), py::arg("curv1"), py::arg("curv2"), py::arg("U"), py::arg("Surf1"), py::arg("Surf2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("curv1"), py::arg("curv2"), py::arg("U"), py::arg("Surf1"), py::arg("Surf2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("curv1"), py::arg("curv2"), py::arg("U"), py::arg("Surf1"), py::arg("Surf2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("curv1"), py::arg("curv2"), py::arg("U"), py::arg("Surf1"), py::arg("Surf2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("curv1"), py::arg("curv2"), py::arg("U"), py::arg("Surf1"), py::arg("Surf2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"), py::arg("Percent"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("curv1"), py::arg("curv2"), py::arg("U"), py::arg("Surf1"), py::arg("Surf2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"), py::arg("Percent"), py::arg("Maxlen"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<>());
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const Standard_Real>(), py::arg("EpsNul"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("EpsNul"), py::arg("EpsC0"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"), py::arg("Percent"));
cls_LocalAnalysis_SurfaceContinuity.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"), py::arg("Percent"), py::arg("Maxlen"));

// Fields

// Methods
// cls_LocalAnalysis_SurfaceContinuity.def_static("operator new_", (void * (*)(size_t)) &LocalAnalysis_SurfaceContinuity::operator new, "None", py::arg("theSize"));
// cls_LocalAnalysis_SurfaceContinuity.def_static("operator delete_", (void (*)(void *)) &LocalAnalysis_SurfaceContinuity::operator delete, "None", py::arg("theAddress"));
// cls_LocalAnalysis_SurfaceContinuity.def_static("operator new[]_", (void * (*)(size_t)) &LocalAnalysis_SurfaceContinuity::operator new[], "None", py::arg("theSize"));
// cls_LocalAnalysis_SurfaceContinuity.def_static("operator delete[]_", (void (*)(void *)) &LocalAnalysis_SurfaceContinuity::operator delete[], "None", py::arg("theAddress"));
// cls_LocalAnalysis_SurfaceContinuity.def_static("operator new_", (void * (*)(size_t, void *)) &LocalAnalysis_SurfaceContinuity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocalAnalysis_SurfaceContinuity.def_static("operator delete_", (void (*)(void *, void *)) &LocalAnalysis_SurfaceContinuity::operator delete, "None", py::arg(""), py::arg(""));
cls_LocalAnalysis_SurfaceContinuity.def("ComputeAnalysis", (void (LocalAnalysis_SurfaceContinuity::*)(GeomLProp_SLProps &, GeomLProp_SLProps &, const GeomAbs_Shape)) &LocalAnalysis_SurfaceContinuity::ComputeAnalysis, "None", py::arg("Surf1"), py::arg("Surf2"), py::arg("Order"));
cls_LocalAnalysis_SurfaceContinuity.def("IsDone", (Standard_Boolean (LocalAnalysis_SurfaceContinuity::*)() const) &LocalAnalysis_SurfaceContinuity::IsDone, "None");
cls_LocalAnalysis_SurfaceContinuity.def("ContinuityStatus", (GeomAbs_Shape (LocalAnalysis_SurfaceContinuity::*)() const) &LocalAnalysis_SurfaceContinuity::ContinuityStatus, "None");
cls_LocalAnalysis_SurfaceContinuity.def("StatusError", (LocalAnalysis_StatusErrorType (LocalAnalysis_SurfaceContinuity::*)() const) &LocalAnalysis_SurfaceContinuity::StatusError, "None");
cls_LocalAnalysis_SurfaceContinuity.def("C0Value", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const) &LocalAnalysis_SurfaceContinuity::C0Value, "None");
cls_LocalAnalysis_SurfaceContinuity.def("C1UAngle", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const) &LocalAnalysis_SurfaceContinuity::C1UAngle, "None");
cls_LocalAnalysis_SurfaceContinuity.def("C1URatio", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const) &LocalAnalysis_SurfaceContinuity::C1URatio, "None");
cls_LocalAnalysis_SurfaceContinuity.def("C1VAngle", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const) &LocalAnalysis_SurfaceContinuity::C1VAngle, "None");
cls_LocalAnalysis_SurfaceContinuity.def("C1VRatio", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const) &LocalAnalysis_SurfaceContinuity::C1VRatio, "None");
cls_LocalAnalysis_SurfaceContinuity.def("C2UAngle", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const) &LocalAnalysis_SurfaceContinuity::C2UAngle, "None");
cls_LocalAnalysis_SurfaceContinuity.def("C2URatio", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const) &LocalAnalysis_SurfaceContinuity::C2URatio, "None");
cls_LocalAnalysis_SurfaceContinuity.def("C2VAngle", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const) &LocalAnalysis_SurfaceContinuity::C2VAngle, "None");
cls_LocalAnalysis_SurfaceContinuity.def("C2VRatio", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const) &LocalAnalysis_SurfaceContinuity::C2VRatio, "None");
cls_LocalAnalysis_SurfaceContinuity.def("G1Angle", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const) &LocalAnalysis_SurfaceContinuity::G1Angle, "None");
cls_LocalAnalysis_SurfaceContinuity.def("G2CurvatureGap", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const) &LocalAnalysis_SurfaceContinuity::G2CurvatureGap, "None");
cls_LocalAnalysis_SurfaceContinuity.def("IsC0", (Standard_Boolean (LocalAnalysis_SurfaceContinuity::*)() const) &LocalAnalysis_SurfaceContinuity::IsC0, "None");
cls_LocalAnalysis_SurfaceContinuity.def("IsC1", (Standard_Boolean (LocalAnalysis_SurfaceContinuity::*)() const) &LocalAnalysis_SurfaceContinuity::IsC1, "None");
cls_LocalAnalysis_SurfaceContinuity.def("IsC2", (Standard_Boolean (LocalAnalysis_SurfaceContinuity::*)() const) &LocalAnalysis_SurfaceContinuity::IsC2, "None");
cls_LocalAnalysis_SurfaceContinuity.def("IsG1", (Standard_Boolean (LocalAnalysis_SurfaceContinuity::*)() const) &LocalAnalysis_SurfaceContinuity::IsG1, "None");
cls_LocalAnalysis_SurfaceContinuity.def("IsG2", (Standard_Boolean (LocalAnalysis_SurfaceContinuity::*)() const) &LocalAnalysis_SurfaceContinuity::IsG2, "None");

// Enums

}
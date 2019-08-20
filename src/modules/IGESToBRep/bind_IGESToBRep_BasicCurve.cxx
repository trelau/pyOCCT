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
#include <IGESToBRep_CurveAndSurface.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <IGESData_IGESEntity.hxx>
#include <Geom2d_Curve.hxx>
#include <IGESGeom_BSplineCurve.hxx>
#include <IGESGeom_CircularArc.hxx>
#include <IGESGeom_ConicArc.hxx>
#include <Geom_BSplineCurve.hxx>
#include <IGESGeom_CopiousData.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <IGESGeom_Line.hxx>
#include <IGESGeom_SplineCurve.hxx>
#include <Geom_Transformation.hxx>
#include <IGESGeom_TransformationMatrix.hxx>
#include <IGESToBRep_BasicCurve.hxx>

void bind_IGESToBRep_BasicCurve(py::module &mod){

py::class_<IGESToBRep_BasicCurve, std::unique_ptr<IGESToBRep_BasicCurve>, IGESToBRep_CurveAndSurface> cls_IGESToBRep_BasicCurve(mod, "IGESToBRep_BasicCurve", "Provides methods to transfer basic geometric curves entities from IGES to CASCADE. These can be : * Circular arc * Conic arc * Spline curve * BSpline curve * Line * Copious data * Point * Transformation matrix");

// Constructors
cls_IGESToBRep_BasicCurve.def(py::init<>());
cls_IGESToBRep_BasicCurve.def(py::init<const IGESToBRep_CurveAndSurface &>(), py::arg("CS"));
cls_IGESToBRep_BasicCurve.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("eps"), py::arg("epsGeom"), py::arg("epsCoeff"), py::arg("mode"), py::arg("modeapprox"), py::arg("optimized"));

// Fields

// Methods
// cls_IGESToBRep_BasicCurve.def_static("operator new_", (void * (*)(size_t)) &IGESToBRep_BasicCurve::operator new, "None", py::arg("theSize"));
// cls_IGESToBRep_BasicCurve.def_static("operator delete_", (void (*)(void *)) &IGESToBRep_BasicCurve::operator delete, "None", py::arg("theAddress"));
// cls_IGESToBRep_BasicCurve.def_static("operator new[]_", (void * (*)(size_t)) &IGESToBRep_BasicCurve::operator new[], "None", py::arg("theSize"));
// cls_IGESToBRep_BasicCurve.def_static("operator delete[]_", (void (*)(void *)) &IGESToBRep_BasicCurve::operator delete[], "None", py::arg("theAddress"));
// cls_IGESToBRep_BasicCurve.def_static("operator new_", (void * (*)(size_t, void *)) &IGESToBRep_BasicCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESToBRep_BasicCurve.def_static("operator delete_", (void (*)(void *, void *)) &IGESToBRep_BasicCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESToBRep_BasicCurve.def("TransferBasicCurve", (opencascade::handle<Geom_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_BasicCurve::TransferBasicCurve, "Transfert a IGESEntity which answer True to the member : IGESToBRep::IsBasicCurve(IGESEntity). If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
cls_IGESToBRep_BasicCurve.def("Transfer2dBasicCurve", (opencascade::handle<Geom2d_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_BasicCurve::Transfer2dBasicCurve, "Transfert a IGESEntity which answer True to the member : IGESToBRep::IsBasicCurve(IGESEntity). The IGESEntity must be a curve UV and its associed TRSF must be planar .If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
cls_IGESToBRep_BasicCurve.def("TransferBSplineCurve", (opencascade::handle<Geom_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_BSplineCurve> &)) &IGESToBRep_BasicCurve::TransferBSplineCurve, "None", py::arg("start"));
cls_IGESToBRep_BasicCurve.def("Transfer2dBSplineCurve", (opencascade::handle<Geom2d_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_BSplineCurve> &)) &IGESToBRep_BasicCurve::Transfer2dBSplineCurve, "None", py::arg("start"));
cls_IGESToBRep_BasicCurve.def("TransferCircularArc", (opencascade::handle<Geom_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_CircularArc> &)) &IGESToBRep_BasicCurve::TransferCircularArc, "None", py::arg("start"));
cls_IGESToBRep_BasicCurve.def("Transfer2dCircularArc", (opencascade::handle<Geom2d_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_CircularArc> &)) &IGESToBRep_BasicCurve::Transfer2dCircularArc, "None", py::arg("start"));
cls_IGESToBRep_BasicCurve.def("TransferConicArc", (opencascade::handle<Geom_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_ConicArc> &)) &IGESToBRep_BasicCurve::TransferConicArc, "None", py::arg("start"));
cls_IGESToBRep_BasicCurve.def("Transfer2dConicArc", (opencascade::handle<Geom2d_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_ConicArc> &)) &IGESToBRep_BasicCurve::Transfer2dConicArc, "None", py::arg("start"));
cls_IGESToBRep_BasicCurve.def("TransferCopiousData", (opencascade::handle<Geom_BSplineCurve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_CopiousData> &)) &IGESToBRep_BasicCurve::TransferCopiousData, "None", py::arg("start"));
cls_IGESToBRep_BasicCurve.def("Transfer2dCopiousData", (opencascade::handle<Geom2d_BSplineCurve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_CopiousData> &)) &IGESToBRep_BasicCurve::Transfer2dCopiousData, "None", py::arg("start"));
cls_IGESToBRep_BasicCurve.def("TransferLine", (opencascade::handle<Geom_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_Line> &)) &IGESToBRep_BasicCurve::TransferLine, "None", py::arg("start"));
cls_IGESToBRep_BasicCurve.def("Transfer2dLine", (opencascade::handle<Geom2d_Curve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_Line> &)) &IGESToBRep_BasicCurve::Transfer2dLine, "None", py::arg("start"));
cls_IGESToBRep_BasicCurve.def("TransferSplineCurve", (opencascade::handle<Geom_BSplineCurve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_SplineCurve> &)) &IGESToBRep_BasicCurve::TransferSplineCurve, "None", py::arg("start"));
cls_IGESToBRep_BasicCurve.def("Transfer2dSplineCurve", (opencascade::handle<Geom2d_BSplineCurve> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_SplineCurve> &)) &IGESToBRep_BasicCurve::Transfer2dSplineCurve, "None", py::arg("start"));
cls_IGESToBRep_BasicCurve.def("TransferTransformation", (opencascade::handle<Geom_Transformation> (IGESToBRep_BasicCurve::*)(const opencascade::handle<IGESGeom_TransformationMatrix> &)) &IGESToBRep_BasicCurve::TransferTransformation, "None", py::arg("start"));

// Enums

}
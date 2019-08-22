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
#include <IGESToBRep_TopoCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESEntity.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Trsf2d.hxx>
#include <TopoDS_Vertex.hxx>
#include <IGESGeom_Point.hxx>
#include <IGESGeom_CompositeCurve.hxx>
#include <IGESGeom_OffsetCurve.hxx>
#include <IGESGeom_CurveOnSurface.hxx>
#include <IGESGeom_Boundary.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Geom2d_Curve.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <TColGeom2d_SequenceOfCurve.hxx>

void bind_IGESToBRep_TopoCurve(py::module &mod){

py::class_<IGESToBRep_TopoCurve, IGESToBRep_CurveAndSurface> cls_IGESToBRep_TopoCurve(mod, "IGESToBRep_TopoCurve", "Provides methods to transfer topologic curves entities from IGES to CASCADE.");

// Constructors
cls_IGESToBRep_TopoCurve.def(py::init<>());
cls_IGESToBRep_TopoCurve.def(py::init<const IGESToBRep_CurveAndSurface &>(), py::arg("CS"));
cls_IGESToBRep_TopoCurve.def(py::init<const IGESToBRep_TopoCurve &>(), py::arg("CS"));
cls_IGESToBRep_TopoCurve.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("eps"), py::arg("epsGeom"), py::arg("epsCoeff"), py::arg("mode"), py::arg("modeapprox"), py::arg("optimized"));

// Fields

// Methods
// cls_IGESToBRep_TopoCurve.def_static("operator new_", (void * (*)(size_t)) &IGESToBRep_TopoCurve::operator new, "None", py::arg("theSize"));
// cls_IGESToBRep_TopoCurve.def_static("operator delete_", (void (*)(void *)) &IGESToBRep_TopoCurve::operator delete, "None", py::arg("theAddress"));
// cls_IGESToBRep_TopoCurve.def_static("operator new[]_", (void * (*)(size_t)) &IGESToBRep_TopoCurve::operator new[], "None", py::arg("theSize"));
// cls_IGESToBRep_TopoCurve.def_static("operator delete[]_", (void (*)(void *)) &IGESToBRep_TopoCurve::operator delete[], "None", py::arg("theAddress"));
// cls_IGESToBRep_TopoCurve.def_static("operator new_", (void * (*)(size_t, void *)) &IGESToBRep_TopoCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESToBRep_TopoCurve.def_static("operator delete_", (void (*)(void *, void *)) &IGESToBRep_TopoCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESToBRep_TopoCurve.def("TransferTopoCurve", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_TopoCurve::TransferTopoCurve, "None", py::arg("start"));
cls_IGESToBRep_TopoCurve.def("Transfer2dTopoCurve", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESData_IGESEntity> &, const TopoDS_Face &, const gp_Trsf2d &, const Standard_Real)) &IGESToBRep_TopoCurve::Transfer2dTopoCurve, "None", py::arg("start"), py::arg("face"), py::arg("trans"), py::arg("uFact"));
cls_IGESToBRep_TopoCurve.def("TransferTopoBasicCurve", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_TopoCurve::TransferTopoBasicCurve, "None", py::arg("start"));
cls_IGESToBRep_TopoCurve.def("Transfer2dTopoBasicCurve", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESData_IGESEntity> &, const TopoDS_Face &, const gp_Trsf2d &, const Standard_Real)) &IGESToBRep_TopoCurve::Transfer2dTopoBasicCurve, "None", py::arg("start"), py::arg("face"), py::arg("trans"), py::arg("uFact"));
cls_IGESToBRep_TopoCurve.def("TransferPoint", (TopoDS_Vertex (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESGeom_Point> &)) &IGESToBRep_TopoCurve::TransferPoint, "None", py::arg("start"));
cls_IGESToBRep_TopoCurve.def("Transfer2dPoint", (TopoDS_Vertex (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESGeom_Point> &)) &IGESToBRep_TopoCurve::Transfer2dPoint, "None", py::arg("start"));
cls_IGESToBRep_TopoCurve.def("TransferCompositeCurve", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESGeom_CompositeCurve> &)) &IGESToBRep_TopoCurve::TransferCompositeCurve, "None", py::arg("start"));
cls_IGESToBRep_TopoCurve.def("Transfer2dCompositeCurve", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESGeom_CompositeCurve> &, const TopoDS_Face &, const gp_Trsf2d &, const Standard_Real)) &IGESToBRep_TopoCurve::Transfer2dCompositeCurve, "None", py::arg("start"), py::arg("face"), py::arg("trans"), py::arg("uFact"));
cls_IGESToBRep_TopoCurve.def("TransferOffsetCurve", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESGeom_OffsetCurve> &)) &IGESToBRep_TopoCurve::TransferOffsetCurve, "None", py::arg("start"));
cls_IGESToBRep_TopoCurve.def("Transfer2dOffsetCurve", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESGeom_OffsetCurve> &, const TopoDS_Face &, const gp_Trsf2d &, const Standard_Real)) &IGESToBRep_TopoCurve::Transfer2dOffsetCurve, "None", py::arg("start"), py::arg("face"), py::arg("trans"), py::arg("uFact"));
cls_IGESToBRep_TopoCurve.def("TransferCurveOnSurface", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESGeom_CurveOnSurface> &)) &IGESToBRep_TopoCurve::TransferCurveOnSurface, "None", py::arg("start"));
cls_IGESToBRep_TopoCurve.def("TransferCurveOnFace", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(TopoDS_Face &, const opencascade::handle<IGESGeom_CurveOnSurface> &, const gp_Trsf2d &, const Standard_Real, const Standard_Boolean)) &IGESToBRep_TopoCurve::TransferCurveOnFace, "Transfers a CurveOnSurface directly on a face to trim it. The CurveOnSurface have to be defined Outer or Inner.", py::arg("face"), py::arg("start"), py::arg("trans"), py::arg("uFact"), py::arg("IsCurv"));
cls_IGESToBRep_TopoCurve.def("TransferBoundary", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(const opencascade::handle<IGESGeom_Boundary> &)) &IGESToBRep_TopoCurve::TransferBoundary, "None", py::arg("start"));
cls_IGESToBRep_TopoCurve.def("TransferBoundaryOnFace", (TopoDS_Shape (IGESToBRep_TopoCurve::*)(TopoDS_Face &, const opencascade::handle<IGESGeom_Boundary> &, const gp_Trsf2d &, const Standard_Real)) &IGESToBRep_TopoCurve::TransferBoundaryOnFace, "Transfers a Boundary directly on a face to trim it.", py::arg("face"), py::arg("start"), py::arg("trans"), py::arg("uFact"));
cls_IGESToBRep_TopoCurve.def("ApproxBSplineCurve", (void (IGESToBRep_TopoCurve::*)(const opencascade::handle<Geom_BSplineCurve> &)) &IGESToBRep_TopoCurve::ApproxBSplineCurve, "None", py::arg("start"));
cls_IGESToBRep_TopoCurve.def("NbCurves", (Standard_Integer (IGESToBRep_TopoCurve::*)() const) &IGESToBRep_TopoCurve::NbCurves, "Returns the count of Curves in 'TheCurves'");
cls_IGESToBRep_TopoCurve.def("Curve", [](IGESToBRep_TopoCurve &self) -> opencascade::handle<Geom_Curve> { return self.Curve(); });
cls_IGESToBRep_TopoCurve.def("Curve", (opencascade::handle<Geom_Curve> (IGESToBRep_TopoCurve::*)(const Standard_Integer) const) &IGESToBRep_TopoCurve::Curve, "Returns a Curve given its rank, by default the first one (null Curvee if out of range) in 'TheCurves'", py::arg("num"));
cls_IGESToBRep_TopoCurve.def("Approx2dBSplineCurve", (void (IGESToBRep_TopoCurve::*)(const opencascade::handle<Geom2d_BSplineCurve> &)) &IGESToBRep_TopoCurve::Approx2dBSplineCurve, "None", py::arg("start"));
cls_IGESToBRep_TopoCurve.def("NbCurves2d", (Standard_Integer (IGESToBRep_TopoCurve::*)() const) &IGESToBRep_TopoCurve::NbCurves2d, "Returns the count of Curves in 'TheCurves2d'");
cls_IGESToBRep_TopoCurve.def("Curve2d", [](IGESToBRep_TopoCurve &self) -> opencascade::handle<Geom2d_Curve> { return self.Curve2d(); });
cls_IGESToBRep_TopoCurve.def("Curve2d", (opencascade::handle<Geom2d_Curve> (IGESToBRep_TopoCurve::*)(const Standard_Integer) const) &IGESToBRep_TopoCurve::Curve2d, "Returns a Curve given its rank, by default the first one (null Curvee if out of range) in 'TheCurves2d'", py::arg("num"));
cls_IGESToBRep_TopoCurve.def("SetBadCase", (void (IGESToBRep_TopoCurve::*)(const Standard_Boolean)) &IGESToBRep_TopoCurve::SetBadCase, "Sets TheBadCase flag", py::arg("value"));
cls_IGESToBRep_TopoCurve.def("BadCase", (Standard_Boolean (IGESToBRep_TopoCurve::*)() const) &IGESToBRep_TopoCurve::BadCase, "Returns TheBadCase flag");

// Enums

}
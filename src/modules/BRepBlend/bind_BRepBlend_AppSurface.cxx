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
#include <AppBlend_Approx.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Approx_SweepFunction.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Standard_OStream.hxx>
#include <Approx_SweepApproximation.hxx>
#include <BRepBlend_AppSurface.hxx>

void bind_BRepBlend_AppSurface(py::module &mod){

py::class_<BRepBlend_AppSurface, std::unique_ptr<BRepBlend_AppSurface, Deleter<BRepBlend_AppSurface>>, AppBlend_Approx> cls_BRepBlend_AppSurface(mod, "BRepBlend_AppSurface", "Used to Approximate the blending surfaces.");

// Constructors
cls_BRepBlend_AppSurface.def(py::init<const opencascade::handle<Approx_SweepFunction> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Funct"), py::arg("First"), py::arg("Last"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("TolAngular"));
cls_BRepBlend_AppSurface.def(py::init<const opencascade::handle<Approx_SweepFunction> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape>(), py::arg("Funct"), py::arg("First"), py::arg("Last"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("TolAngular"), py::arg("Continuity"));
cls_BRepBlend_AppSurface.def(py::init<const opencascade::handle<Approx_SweepFunction> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer>(), py::arg("Funct"), py::arg("First"), py::arg("Last"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("TolAngular"), py::arg("Continuity"), py::arg("Degmax"));
cls_BRepBlend_AppSurface.def(py::init<const opencascade::handle<Approx_SweepFunction> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("Funct"), py::arg("First"), py::arg("Last"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("TolAngular"), py::arg("Continuity"), py::arg("Degmax"), py::arg("Segmax"));

// Fields

// Methods
// cls_BRepBlend_AppSurface.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_AppSurface::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_AppSurface.def_static("operator delete_", (void (*)(void *)) &BRepBlend_AppSurface::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_AppSurface.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_AppSurface::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_AppSurface.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_AppSurface::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_AppSurface.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_AppSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_AppSurface.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_AppSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_AppSurface.def("IsDone", (Standard_Boolean (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::IsDone, "None");
cls_BRepBlend_AppSurface.def("SurfShape", [](BRepBlend_AppSurface &self, Standard_Integer & UDegree, Standard_Integer & VDegree, Standard_Integer & NbUPoles, Standard_Integer & NbVPoles, Standard_Integer & NbUKnots, Standard_Integer & NbVKnots){ self.SurfShape(UDegree, VDegree, NbUPoles, NbVPoles, NbUKnots, NbVKnots); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(UDegree, VDegree, NbUPoles, NbVPoles, NbUKnots, NbVKnots); }, "None", py::arg("UDegree"), py::arg("VDegree"), py::arg("NbUPoles"), py::arg("NbVPoles"), py::arg("NbUKnots"), py::arg("NbVKnots"));
cls_BRepBlend_AppSurface.def("Surface", (void (BRepBlend_AppSurface::*)(TColgp_Array2OfPnt &, TColStd_Array2OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &, TColStd_Array1OfInteger &) const) &BRepBlend_AppSurface::Surface, "None", py::arg("TPoles"), py::arg("TWeights"), py::arg("TUKnots"), py::arg("TVKnots"), py::arg("TUMults"), py::arg("TVMults"));
cls_BRepBlend_AppSurface.def("UDegree", (Standard_Integer (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::UDegree, "None");
cls_BRepBlend_AppSurface.def("VDegree", (Standard_Integer (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::VDegree, "None");
cls_BRepBlend_AppSurface.def("SurfPoles", (const TColgp_Array2OfPnt & (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::SurfPoles, "None");
cls_BRepBlend_AppSurface.def("SurfWeights", (const TColStd_Array2OfReal & (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::SurfWeights, "None");
cls_BRepBlend_AppSurface.def("SurfUKnots", (const TColStd_Array1OfReal & (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::SurfUKnots, "None");
cls_BRepBlend_AppSurface.def("SurfVKnots", (const TColStd_Array1OfReal & (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::SurfVKnots, "None");
cls_BRepBlend_AppSurface.def("SurfUMults", (const TColStd_Array1OfInteger & (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::SurfUMults, "None");
cls_BRepBlend_AppSurface.def("SurfVMults", (const TColStd_Array1OfInteger & (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::SurfVMults, "None");
cls_BRepBlend_AppSurface.def("MaxErrorOnSurf", (Standard_Real (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::MaxErrorOnSurf, "returns the maximum error in the suface approximation.");
cls_BRepBlend_AppSurface.def("NbCurves2d", (Standard_Integer (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::NbCurves2d, "None");
cls_BRepBlend_AppSurface.def("Curves2dShape", [](BRepBlend_AppSurface &self, Standard_Integer & Degree, Standard_Integer & NbPoles, Standard_Integer & NbKnots){ self.Curves2dShape(Degree, NbPoles, NbKnots); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(Degree, NbPoles, NbKnots); }, "None", py::arg("Degree"), py::arg("NbPoles"), py::arg("NbKnots"));
cls_BRepBlend_AppSurface.def("Curve2d", (void (BRepBlend_AppSurface::*)(const Standard_Integer, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &) const) &BRepBlend_AppSurface::Curve2d, "None", py::arg("Index"), py::arg("TPoles"), py::arg("TKnots"), py::arg("TMults"));
cls_BRepBlend_AppSurface.def("Curves2dDegree", (Standard_Integer (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::Curves2dDegree, "None");
cls_BRepBlend_AppSurface.def("Curve2dPoles", (const TColgp_Array1OfPnt2d & (BRepBlend_AppSurface::*)(const Standard_Integer) const) &BRepBlend_AppSurface::Curve2dPoles, "None", py::arg("Index"));
cls_BRepBlend_AppSurface.def("Curves2dKnots", (const TColStd_Array1OfReal & (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::Curves2dKnots, "None");
cls_BRepBlend_AppSurface.def("Curves2dMults", (const TColStd_Array1OfInteger & (BRepBlend_AppSurface::*)() const) &BRepBlend_AppSurface::Curves2dMults, "None");
cls_BRepBlend_AppSurface.def("TolReached", [](BRepBlend_AppSurface &self, Standard_Real & Tol3d, Standard_Real & Tol2d){ self.TolReached(Tol3d, Tol2d); return std::tuple<Standard_Real &, Standard_Real &>(Tol3d, Tol2d); }, "None", py::arg("Tol3d"), py::arg("Tol2d"));
cls_BRepBlend_AppSurface.def("Max2dError", (Standard_Real (BRepBlend_AppSurface::*)(const Standard_Integer) const) &BRepBlend_AppSurface::Max2dError, "returns the maximum error in the <Index> 2d curve approximation.", py::arg("Index"));
cls_BRepBlend_AppSurface.def("TolCurveOnSurf", (Standard_Real (BRepBlend_AppSurface::*)(const Standard_Integer) const) &BRepBlend_AppSurface::TolCurveOnSurf, "None", py::arg("Index"));
cls_BRepBlend_AppSurface.def("Dump", (void (BRepBlend_AppSurface::*)(Standard_OStream &) const) &BRepBlend_AppSurface::Dump, "diplay information on approximation.", py::arg("o"));

// Enums

}
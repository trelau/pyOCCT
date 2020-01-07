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
#include <TColgp_Array2OfPnt.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <AppBlend_Approx.hxx>

PYBIND11_MODULE(AppBlend, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");

// CLASS: APPBLEND_APPROX
py::class_<AppBlend_Approx> cls_AppBlend_Approx(mod, "AppBlend_Approx", "Bspline approximation of a surface.");

// Methods
// cls_AppBlend_Approx.def_static("operator new_", (void * (*)(size_t)) &AppBlend_Approx::operator new, "None", py::arg("theSize"));
// cls_AppBlend_Approx.def_static("operator delete_", (void (*)(void *)) &AppBlend_Approx::operator delete, "None", py::arg("theAddress"));
// cls_AppBlend_Approx.def_static("operator new[]_", (void * (*)(size_t)) &AppBlend_Approx::operator new[], "None", py::arg("theSize"));
// cls_AppBlend_Approx.def_static("operator delete[]_", (void (*)(void *)) &AppBlend_Approx::operator delete[], "None", py::arg("theAddress"));
// cls_AppBlend_Approx.def_static("operator new_", (void * (*)(size_t, void *)) &AppBlend_Approx::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppBlend_Approx.def_static("operator delete_", (void (*)(void *, void *)) &AppBlend_Approx::operator delete, "None", py::arg(""), py::arg(""));
cls_AppBlend_Approx.def("IsDone", (Standard_Boolean (AppBlend_Approx::*)() const) &AppBlend_Approx::IsDone, "None");
cls_AppBlend_Approx.def("SurfShape", [](AppBlend_Approx &self, Standard_Integer & UDegree, Standard_Integer & VDegree, Standard_Integer & NbUPoles, Standard_Integer & NbVPoles, Standard_Integer & NbUKnots, Standard_Integer & NbVKnots){ self.SurfShape(UDegree, VDegree, NbUPoles, NbVPoles, NbUKnots, NbVKnots); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(UDegree, VDegree, NbUPoles, NbVPoles, NbUKnots, NbVKnots); }, "None", py::arg("UDegree"), py::arg("VDegree"), py::arg("NbUPoles"), py::arg("NbVPoles"), py::arg("NbUKnots"), py::arg("NbVKnots"));
cls_AppBlend_Approx.def("Surface", (void (AppBlend_Approx::*)(TColgp_Array2OfPnt &, TColStd_Array2OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &, TColStd_Array1OfInteger &) const) &AppBlend_Approx::Surface, "None", py::arg("TPoles"), py::arg("TWeights"), py::arg("TUKnots"), py::arg("TVKnots"), py::arg("TUMults"), py::arg("TVMults"));
cls_AppBlend_Approx.def("UDegree", (Standard_Integer (AppBlend_Approx::*)() const) &AppBlend_Approx::UDegree, "None");
cls_AppBlend_Approx.def("VDegree", (Standard_Integer (AppBlend_Approx::*)() const) &AppBlend_Approx::VDegree, "None");
cls_AppBlend_Approx.def("SurfPoles", (const TColgp_Array2OfPnt & (AppBlend_Approx::*)() const) &AppBlend_Approx::SurfPoles, "None");
cls_AppBlend_Approx.def("SurfWeights", (const TColStd_Array2OfReal & (AppBlend_Approx::*)() const) &AppBlend_Approx::SurfWeights, "None");
cls_AppBlend_Approx.def("SurfUKnots", (const TColStd_Array1OfReal & (AppBlend_Approx::*)() const) &AppBlend_Approx::SurfUKnots, "None");
cls_AppBlend_Approx.def("SurfVKnots", (const TColStd_Array1OfReal & (AppBlend_Approx::*)() const) &AppBlend_Approx::SurfVKnots, "None");
cls_AppBlend_Approx.def("SurfUMults", (const TColStd_Array1OfInteger & (AppBlend_Approx::*)() const) &AppBlend_Approx::SurfUMults, "None");
cls_AppBlend_Approx.def("SurfVMults", (const TColStd_Array1OfInteger & (AppBlend_Approx::*)() const) &AppBlend_Approx::SurfVMults, "None");
cls_AppBlend_Approx.def("NbCurves2d", (Standard_Integer (AppBlend_Approx::*)() const) &AppBlend_Approx::NbCurves2d, "None");
cls_AppBlend_Approx.def("Curves2dShape", [](AppBlend_Approx &self, Standard_Integer & Degree, Standard_Integer & NbPoles, Standard_Integer & NbKnots){ self.Curves2dShape(Degree, NbPoles, NbKnots); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(Degree, NbPoles, NbKnots); }, "None", py::arg("Degree"), py::arg("NbPoles"), py::arg("NbKnots"));
cls_AppBlend_Approx.def("Curve2d", (void (AppBlend_Approx::*)(const Standard_Integer, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &) const) &AppBlend_Approx::Curve2d, "None", py::arg("Index"), py::arg("TPoles"), py::arg("TKnots"), py::arg("TMults"));
cls_AppBlend_Approx.def("Curves2dDegree", (Standard_Integer (AppBlend_Approx::*)() const) &AppBlend_Approx::Curves2dDegree, "None");
cls_AppBlend_Approx.def("Curve2dPoles", (const TColgp_Array1OfPnt2d & (AppBlend_Approx::*)(const Standard_Integer) const) &AppBlend_Approx::Curve2dPoles, "None", py::arg("Index"));
cls_AppBlend_Approx.def("Curves2dKnots", (const TColStd_Array1OfReal & (AppBlend_Approx::*)() const) &AppBlend_Approx::Curves2dKnots, "None");
cls_AppBlend_Approx.def("Curves2dMults", (const TColStd_Array1OfInteger & (AppBlend_Approx::*)() const) &AppBlend_Approx::Curves2dMults, "None");
cls_AppBlend_Approx.def("TolReached", [](AppBlend_Approx &self, Standard_Real & Tol3d, Standard_Real & Tol2d){ self.TolReached(Tol3d, Tol2d); return std::tuple<Standard_Real &, Standard_Real &>(Tol3d, Tol2d); }, "None", py::arg("Tol3d"), py::arg("Tol2d"));
cls_AppBlend_Approx.def("TolCurveOnSurf", (Standard_Real (AppBlend_Approx::*)(const Standard_Integer) const) &AppBlend_Approx::TolCurveOnSurf, "None", py::arg("Index"));


}

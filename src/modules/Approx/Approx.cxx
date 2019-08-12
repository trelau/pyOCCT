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

void bind_Approx_ParametrizationType(py::module &);
void bind_Approx_Status(py::module &);
void bind_Approx_SequenceOfHArray1OfReal(py::module &);
void bind_Approx_Array1OfAdHSurface(py::module &);
void bind_Approx_Array1OfGTrsf2d(py::module &);
void bind_Approx_Curve2d(py::module &);
void bind_Approx_Curve3d(py::module &);
void bind_Approx_CurveOnSurface(py::module &);
void bind_Approx_CurvilinearParameter(py::module &);
void bind_Approx_CurvlinFunc(py::module &);
void bind_Approx_FitAndDivide(py::module &);
void bind_Approx_FitAndDivide2d(py::module &);
void bind_Approx_HArray1OfAdHSurface(py::module &);
void bind_Approx_HArray1OfGTrsf2d(py::module &);
void bind_Approx_MCurvesToBSpCurve(py::module &);
void bind_Approx_SameParameter(py::module &);
void bind_Approx_SweepApproximation(py::module &);
void bind_Approx_SweepFunction(py::module &);

PYBIND11_MODULE(Approx, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.gp");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Geom");
py::module::import("OCCT.AppCont");
py::module::import("OCCT.AppParCurves");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.AdvApprox");

bind_Approx_ParametrizationType(mod);
bind_Approx_Status(mod);
bind_Approx_SequenceOfHArray1OfReal(mod);
bind_Approx_Array1OfAdHSurface(mod);
bind_Approx_Array1OfGTrsf2d(mod);
bind_Approx_Curve2d(mod);
bind_Approx_Curve3d(mod);
bind_Approx_CurveOnSurface(mod);
bind_Approx_CurvilinearParameter(mod);
bind_Approx_CurvlinFunc(mod);
bind_Approx_FitAndDivide(mod);
bind_Approx_FitAndDivide2d(mod);
bind_Approx_HArray1OfAdHSurface(mod);
bind_Approx_HArray1OfGTrsf2d(mod);
bind_Approx_MCurvesToBSpCurve(mod);
bind_Approx_SameParameter(mod);
bind_Approx_SweepApproximation(mod);
bind_Approx_SweepFunction(mod);

}

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

void bind_BRepApprox_TheComputeLineOfApprox(py::module &);
void bind_BRepApprox_TheComputeLineBezierOfApprox(py::module &);
void bind_BRepApprox_Approx(py::module &);
void bind_BRepApprox_ApproxLine(py::module &);
void bind_BRepApprox_BSpGradient_BFGSOfMyBSplGradientOfTheComputeLineOfApprox(py::module &);
void bind_BRepApprox_TheMultiLineOfApprox(py::module &);
void bind_BRepApprox_BSpParLeastSquareOfMyBSplGradientOfTheComputeLineOfApprox(py::module &);
void bind_BRepApprox_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfApprox(py::module &);
void bind_BRepApprox_Gradient_BFGSOfMyGradientbisOfTheComputeLineOfApprox(py::module &);
void bind_BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox(py::module &);
void bind_BRepApprox_MyBSplGradientOfTheComputeLineOfApprox(py::module &);
void bind_BRepApprox_MyGradientbisOfTheComputeLineOfApprox(py::module &);
void bind_BRepApprox_MyGradientOfTheComputeLineBezierOfApprox(py::module &);
void bind_BRepApprox_ParLeastSquareOfMyGradientbisOfTheComputeLineOfApprox(py::module &);
void bind_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox(py::module &);
void bind_BRepApprox_ParLeastSquareOfMyGradientOfTheComputeLineBezierOfApprox(py::module &);
void bind_BRepApprox_ParFunctionOfMyGradientOfTheComputeLineBezierOfApprox(py::module &);
void bind_BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox(py::module &);
void bind_BRepApprox_ResConstraintOfMyGradientOfTheComputeLineBezierOfApprox(py::module &);
void bind_BRepApprox_SurfaceTool(py::module &);
void bind_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox(py::module &);
void bind_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox(py::module &);
void bind_BRepApprox_TheImpPrmSvSurfacesOfApprox(py::module &);
void bind_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox(py::module &);
void bind_BRepApprox_TheMultiLineToolOfApprox(py::module &);
void bind_BRepApprox_ThePrmPrmSvSurfacesOfApprox(py::module &);

PYBIND11_MODULE(BRepApprox, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Approx");
py::module::import("OCCT.math");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.AppParCurves");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.IntSurf");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.gp");
py::module::import("OCCT.IntImp");
py::module::import("OCCT.ApproxInt");

bind_BRepApprox_TheComputeLineOfApprox(mod);
bind_BRepApprox_TheComputeLineBezierOfApprox(mod);
bind_BRepApprox_Approx(mod);
bind_BRepApprox_ApproxLine(mod);
bind_BRepApprox_BSpGradient_BFGSOfMyBSplGradientOfTheComputeLineOfApprox(mod);
bind_BRepApprox_TheMultiLineOfApprox(mod);
bind_BRepApprox_BSpParLeastSquareOfMyBSplGradientOfTheComputeLineOfApprox(mod);
bind_BRepApprox_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfApprox(mod);
bind_BRepApprox_Gradient_BFGSOfMyGradientbisOfTheComputeLineOfApprox(mod);
bind_BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox(mod);
bind_BRepApprox_MyBSplGradientOfTheComputeLineOfApprox(mod);
bind_BRepApprox_MyGradientbisOfTheComputeLineOfApprox(mod);
bind_BRepApprox_MyGradientOfTheComputeLineBezierOfApprox(mod);
bind_BRepApprox_ParLeastSquareOfMyGradientbisOfTheComputeLineOfApprox(mod);
bind_BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox(mod);
bind_BRepApprox_ParLeastSquareOfMyGradientOfTheComputeLineBezierOfApprox(mod);
bind_BRepApprox_ParFunctionOfMyGradientOfTheComputeLineBezierOfApprox(mod);
bind_BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox(mod);
bind_BRepApprox_ResConstraintOfMyGradientOfTheComputeLineBezierOfApprox(mod);
bind_BRepApprox_SurfaceTool(mod);
bind_BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox(mod);
bind_BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox(mod);
bind_BRepApprox_TheImpPrmSvSurfacesOfApprox(mod);
bind_BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox(mod);
bind_BRepApprox_TheMultiLineToolOfApprox(mod);
bind_BRepApprox_ThePrmPrmSvSurfacesOfApprox(mod);

}

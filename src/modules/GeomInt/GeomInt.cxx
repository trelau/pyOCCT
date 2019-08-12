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

void bind_GeomInt_LineConstructor(py::module &);
void bind_GeomInt_VectorOfReal(py::module &);
void bind_GeomInt_IntSS(py::module &);
void bind_GeomInt(py::module &);
void bind_GeomInt_BSpGradient_BFGSOfMyBSplGradientOfTheComputeLineOfWLApprox(py::module &);
void bind_GeomInt_TheMultiLineOfWLApprox(py::module &);
void bind_GeomInt_BSpParLeastSquareOfMyBSplGradientOfTheComputeLineOfWLApprox(py::module &);
void bind_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox(py::module &);
void bind_GeomInt_Gradient_BFGSOfMyGradientbisOfTheComputeLineOfWLApprox(py::module &);
void bind_GeomInt_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfWLApprox(py::module &);
void bind_GeomInt_LineTool(py::module &);
void bind_GeomInt_MyBSplGradientOfTheComputeLineOfWLApprox(py::module &);
void bind_GeomInt_MyGradientbisOfTheComputeLineOfWLApprox(py::module &);
void bind_GeomInt_MyGradientOfTheComputeLineBezierOfWLApprox(py::module &);
void bind_GeomInt_ParameterAndOrientation(py::module &);
void bind_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox(py::module &);
void bind_GeomInt_ParFunctionOfMyGradientbisOfTheComputeLineOfWLApprox(py::module &);
void bind_GeomInt_ParLeastSquareOfMyGradientOfTheComputeLineBezierOfWLApprox(py::module &);
void bind_GeomInt_ParFunctionOfMyGradientOfTheComputeLineBezierOfWLApprox(py::module &);
void bind_GeomInt_ResConstraintOfMyGradientbisOfTheComputeLineOfWLApprox(py::module &);
void bind_GeomInt_ResConstraintOfMyGradientOfTheComputeLineBezierOfWLApprox(py::module &);
void bind_GeomInt_SequenceOfParameterAndOrientation(py::module &);
void bind_GeomInt_TheComputeLineBezierOfWLApprox(py::module &);
void bind_GeomInt_TheComputeLineOfWLApprox(py::module &);
void bind_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox(py::module &);
void bind_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox(py::module &);
void bind_GeomInt_TheImpPrmSvSurfacesOfWLApprox(py::module &);
void bind_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox(py::module &);
void bind_GeomInt_TheMultiLineToolOfWLApprox(py::module &);
void bind_GeomInt_ThePrmPrmSvSurfacesOfWLApprox(py::module &);
void bind_GeomInt_WLApprox(py::module &);

PYBIND11_MODULE(GeomInt, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.GeomAdaptor");
py::module::import("OCCT.IntPatch");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.gp");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TColGeom");
py::module::import("OCCT.TColGeom2d");
py::module::import("OCCT.math");
py::module::import("OCCT.Approx");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.AppParCurves");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.IntImp");
py::module::import("OCCT.IntSurf");
py::module::import("OCCT.ApproxInt");

bind_GeomInt_LineConstructor(mod);
bind_GeomInt_VectorOfReal(mod);
bind_GeomInt_IntSS(mod);
bind_GeomInt(mod);
bind_GeomInt_BSpGradient_BFGSOfMyBSplGradientOfTheComputeLineOfWLApprox(mod);
bind_GeomInt_TheMultiLineOfWLApprox(mod);
bind_GeomInt_BSpParLeastSquareOfMyBSplGradientOfTheComputeLineOfWLApprox(mod);
bind_GeomInt_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfWLApprox(mod);
bind_GeomInt_Gradient_BFGSOfMyGradientbisOfTheComputeLineOfWLApprox(mod);
bind_GeomInt_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfWLApprox(mod);
bind_GeomInt_LineTool(mod);
bind_GeomInt_MyBSplGradientOfTheComputeLineOfWLApprox(mod);
bind_GeomInt_MyGradientbisOfTheComputeLineOfWLApprox(mod);
bind_GeomInt_MyGradientOfTheComputeLineBezierOfWLApprox(mod);
bind_GeomInt_ParameterAndOrientation(mod);
bind_GeomInt_ParLeastSquareOfMyGradientbisOfTheComputeLineOfWLApprox(mod);
bind_GeomInt_ParFunctionOfMyGradientbisOfTheComputeLineOfWLApprox(mod);
bind_GeomInt_ParLeastSquareOfMyGradientOfTheComputeLineBezierOfWLApprox(mod);
bind_GeomInt_ParFunctionOfMyGradientOfTheComputeLineBezierOfWLApprox(mod);
bind_GeomInt_ResConstraintOfMyGradientbisOfTheComputeLineOfWLApprox(mod);
bind_GeomInt_ResConstraintOfMyGradientOfTheComputeLineBezierOfWLApprox(mod);
bind_GeomInt_SequenceOfParameterAndOrientation(mod);
bind_GeomInt_TheComputeLineBezierOfWLApprox(mod);
bind_GeomInt_TheComputeLineOfWLApprox(mod);
bind_GeomInt_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfWLApprox(mod);
bind_GeomInt_TheZerImpFuncOfTheImpPrmSvSurfacesOfWLApprox(mod);
bind_GeomInt_TheImpPrmSvSurfacesOfWLApprox(mod);
bind_GeomInt_TheInt2SOfThePrmPrmSvSurfacesOfWLApprox(mod);
bind_GeomInt_TheMultiLineToolOfWLApprox(mod);
bind_GeomInt_ThePrmPrmSvSurfacesOfWLApprox(mod);
bind_GeomInt_WLApprox(mod);

}

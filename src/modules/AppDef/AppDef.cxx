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

void bind_AppDef_MultiPointConstraint(py::module &);
void bind_AppDef_Array1OfMultiPointConstraint(py::module &);
void bind_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute(py::module &);
void bind_AppDef_BSplineCompute(py::module &);
void bind_AppDef_HArray1OfMultiPointConstraint(py::module &);
void bind_AppDef_MultiLine(py::module &);
void bind_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute(py::module &);
void bind_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute(py::module &);
void bind_AppDef_Compute(py::module &);
void bind_AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute(py::module &);
void bind_AppDef_Gradient_BFGSOfMyGradientOfCompute(py::module &);
void bind_AppDef_Gradient_BFGSOfTheGradient(py::module &);
void bind_AppDef_SmoothCriterion(py::module &);
void bind_AppDef_LinearCriteria(py::module &);
void bind_AppDef_MyBSplGradientOfBSplineCompute(py::module &);
void bind_AppDef_MyGradientbisOfBSplineCompute(py::module &);
void bind_AppDef_MyGradientOfCompute(py::module &);
void bind_AppDef_MyLineTool(py::module &);
void bind_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute(py::module &);
void bind_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute(py::module &);
void bind_AppDef_ParLeastSquareOfMyGradientOfCompute(py::module &);
void bind_AppDef_ParFunctionOfMyGradientOfCompute(py::module &);
void bind_AppDef_ParLeastSquareOfTheGradient(py::module &);
void bind_AppDef_ParFunctionOfTheGradient(py::module &);
void bind_AppDef_ResConstraintOfMyGradientbisOfBSplineCompute(py::module &);
void bind_AppDef_ResConstraintOfMyGradientOfCompute(py::module &);
void bind_AppDef_ResConstraintOfTheGradient(py::module &);
void bind_AppDef_TheLeastSquares(py::module &);
void bind_AppDef_TheFunction(py::module &);
void bind_AppDef_TheGradient(py::module &);
void bind_AppDef_TheResol(py::module &);
void bind_AppDef_Variational(py::module &);

PYBIND11_MODULE(AppDef, mod) {

py::module::import("OCCT.AppParCurves");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.math");
py::module::import("OCCT.Approx");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.FEmTool");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.PLib");

bind_AppDef_MultiPointConstraint(mod);
bind_AppDef_Array1OfMultiPointConstraint(mod);
bind_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute(mod);
bind_AppDef_BSplineCompute(mod);
bind_AppDef_HArray1OfMultiPointConstraint(mod);
bind_AppDef_MultiLine(mod);
bind_AppDef_BSpParLeastSquareOfMyBSplGradientOfBSplineCompute(mod);
bind_AppDef_BSpParFunctionOfMyBSplGradientOfBSplineCompute(mod);
bind_AppDef_Compute(mod);
bind_AppDef_Gradient_BFGSOfMyGradientbisOfBSplineCompute(mod);
bind_AppDef_Gradient_BFGSOfMyGradientOfCompute(mod);
bind_AppDef_Gradient_BFGSOfTheGradient(mod);
bind_AppDef_SmoothCriterion(mod);
bind_AppDef_LinearCriteria(mod);
bind_AppDef_MyBSplGradientOfBSplineCompute(mod);
bind_AppDef_MyGradientbisOfBSplineCompute(mod);
bind_AppDef_MyGradientOfCompute(mod);
bind_AppDef_MyLineTool(mod);
bind_AppDef_ParLeastSquareOfMyGradientbisOfBSplineCompute(mod);
bind_AppDef_ParFunctionOfMyGradientbisOfBSplineCompute(mod);
bind_AppDef_ParLeastSquareOfMyGradientOfCompute(mod);
bind_AppDef_ParFunctionOfMyGradientOfCompute(mod);
bind_AppDef_ParLeastSquareOfTheGradient(mod);
bind_AppDef_ParFunctionOfTheGradient(mod);
bind_AppDef_ResConstraintOfMyGradientbisOfBSplineCompute(mod);
bind_AppDef_ResConstraintOfMyGradientOfCompute(mod);
bind_AppDef_ResConstraintOfTheGradient(mod);
bind_AppDef_TheLeastSquares(mod);
bind_AppDef_TheFunction(mod);
bind_AppDef_TheGradient(mod);
bind_AppDef_TheResol(mod);
bind_AppDef_Variational(mod);

}

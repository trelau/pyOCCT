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

void bind_Convert_ParameterisationType(py::module &);
void bind_Convert_ConicToBSplineCurve(py::module &);
void bind_Convert_CircleToBSplineCurve(py::module &);
void bind_Convert_SequenceOfArray1OfPoles2d(py::module &);
void bind_Convert_CompBezierCurves2dToBSplineCurve2d(py::module &);
void bind_Convert_SequenceOfArray1OfPoles(py::module &);
void bind_Convert_CompBezierCurvesToBSplineCurve(py::module &);
void bind_Convert_CompPolynomialToPoles(py::module &);
void bind_Convert_ElementarySurfaceToBSplineSurface(py::module &);
void bind_Convert_ConeToBSplineSurface(py::module &);
void bind_Convert_CosAndSinEvalFunction(py::module &);
void bind_Convert_CylinderToBSplineSurface(py::module &);
void bind_Convert_EllipseToBSplineCurve(py::module &);
void bind_Convert_GridPolynomialToPoles(py::module &);
void bind_Convert_HyperbolaToBSplineCurve(py::module &);
void bind_Convert_ParabolaToBSplineCurve(py::module &);
void bind_Convert_SphereToBSplineSurface(py::module &);
void bind_Convert_TorusToBSplineSurface(py::module &);

PYBIND11_MODULE(Convert, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.NCollection");

bind_Convert_ParameterisationType(mod);
bind_Convert_ConicToBSplineCurve(mod);
bind_Convert_CircleToBSplineCurve(mod);
bind_Convert_SequenceOfArray1OfPoles2d(mod);
bind_Convert_CompBezierCurves2dToBSplineCurve2d(mod);
bind_Convert_SequenceOfArray1OfPoles(mod);
bind_Convert_CompBezierCurvesToBSplineCurve(mod);
bind_Convert_CompPolynomialToPoles(mod);
bind_Convert_ElementarySurfaceToBSplineSurface(mod);
bind_Convert_ConeToBSplineSurface(mod);
bind_Convert_CosAndSinEvalFunction(mod);
bind_Convert_CylinderToBSplineSurface(mod);
bind_Convert_EllipseToBSplineCurve(mod);
bind_Convert_GridPolynomialToPoles(mod);
bind_Convert_HyperbolaToBSplineCurve(mod);
bind_Convert_ParabolaToBSplineCurve(mod);
bind_Convert_SphereToBSplineSurface(mod);
bind_Convert_TorusToBSplineSurface(mod);

}

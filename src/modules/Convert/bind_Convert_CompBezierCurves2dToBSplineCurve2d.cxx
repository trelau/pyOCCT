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
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Convert_SequenceOfArray1OfPoles2d.hxx>
#include <TColgp_SequenceOfPnt2d.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <Convert_CompBezierCurves2dToBSplineCurve2d.hxx>

void bind_Convert_CompBezierCurves2dToBSplineCurve2d(py::module &mod){

py::class_<Convert_CompBezierCurves2dToBSplineCurve2d, std::unique_ptr<Convert_CompBezierCurves2dToBSplineCurve2d, Deleter<Convert_CompBezierCurves2dToBSplineCurve2d>>> cls_Convert_CompBezierCurves2dToBSplineCurve2d(mod, "Convert_CompBezierCurves2dToBSplineCurve2d", "Converts a list of connecting Bezier Curves 2d to a BSplineCurve 2d. if possible, the continuity of the BSpline will be increased to more than C0.");

// Constructors
cls_Convert_CompBezierCurves2dToBSplineCurve2d.def(py::init<>());
cls_Convert_CompBezierCurves2dToBSplineCurve2d.def(py::init<const Standard_Real>(), py::arg("AngularTolerance"));

// Fields

// Methods
// cls_Convert_CompBezierCurves2dToBSplineCurve2d.def_static("operator new_", (void * (*)(size_t)) &Convert_CompBezierCurves2dToBSplineCurve2d::operator new, "None", py::arg("theSize"));
// cls_Convert_CompBezierCurves2dToBSplineCurve2d.def_static("operator delete_", (void (*)(void *)) &Convert_CompBezierCurves2dToBSplineCurve2d::operator delete, "None", py::arg("theAddress"));
// cls_Convert_CompBezierCurves2dToBSplineCurve2d.def_static("operator new[]_", (void * (*)(size_t)) &Convert_CompBezierCurves2dToBSplineCurve2d::operator new[], "None", py::arg("theSize"));
// cls_Convert_CompBezierCurves2dToBSplineCurve2d.def_static("operator delete[]_", (void (*)(void *)) &Convert_CompBezierCurves2dToBSplineCurve2d::operator delete[], "None", py::arg("theAddress"));
// cls_Convert_CompBezierCurves2dToBSplineCurve2d.def_static("operator new_", (void * (*)(size_t, void *)) &Convert_CompBezierCurves2dToBSplineCurve2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Convert_CompBezierCurves2dToBSplineCurve2d.def_static("operator delete_", (void (*)(void *, void *)) &Convert_CompBezierCurves2dToBSplineCurve2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Convert_CompBezierCurves2dToBSplineCurve2d.def("AddCurve", (void (Convert_CompBezierCurves2dToBSplineCurve2d::*)(const TColgp_Array1OfPnt2d &)) &Convert_CompBezierCurves2dToBSplineCurve2d::AddCurve, "Adds the Bezier curve defined by the table of poles Poles, to the sequence (still contained in this framework) of adjacent Bezier curves to be converted into a BSpline curve. Only polynomial (i.e. non-rational) Bezier curves are converted using this framework. If this is not the first call to the function (i.e. if this framework still contains data in its sequence of Bezier curves), the degree of continuity of the BSpline curve will be increased at the time of computation at the first point of the added Bezier curve (i.e. the first point of the Poles table). This will be the case if the tangent vector of the curve at this point is parallel to the tangent vector at the end point of the preceding Bezier curve in the sequence of Bezier curves still contained in this framework. An angular tolerance given at the time of construction of this framework, will be used to check the parallelism of the two tangent vectors. This checking procedure, and all the relative computations will be performed by the function Perform. When the sequence of adjacent Bezier curves is complete, use the following functions: - Perform to compute the data needed to build the BSpline curve, - and the available consultation functions to access the computed data. This data may be used to construct the BSpline curve. Warning The sequence of Bezier curves treated by this framework is automatically initialized with the first Bezier curve when the function is first called. During subsequent use of this function, ensure that the first point of the added Bezier curve (i.e. the first point of the Poles table) is coincident with the last point of the sequence (i.e. the last point of the preceding Bezier curve in the sequence) of Bezier curves still contained in this framework. An error may occur at the time of computation if this condition is not satisfied. Particular care must be taken with respect to the above, as this condition is not checked either when defining the sequence of Bezier curves or at the time of computation.", py::arg("Poles"));
cls_Convert_CompBezierCurves2dToBSplineCurve2d.def("Perform", (void (Convert_CompBezierCurves2dToBSplineCurve2d::*)()) &Convert_CompBezierCurves2dToBSplineCurve2d::Perform, "Computes all the data needed to build a BSpline curve equivalent to the sequence of adjacent Bezier curves still contained in this framework. A knot is inserted on the computed BSpline curve at the junction point of two consecutive Bezier curves. The degree of continuity of the BSpline curve will be increased at the junction point of two consecutive Bezier curves if their tangent vectors at this point are parallel. An angular tolerance given at the time of construction of this framework is used to check the parallelism of the two tangent vectors. Use the available consultation functions to access the computed data. This data may then be used to construct the BSpline curve. Warning Ensure that the curves in the sequence of Bezier curves contained in this framework are adjacent. An error may occur at the time of computation if this condition is not satisfied. Particular care must be taken with respect to the above as this condition is not checked, either when defining the Bezier curve sequence or at the time of computation.");
cls_Convert_CompBezierCurves2dToBSplineCurve2d.def("Degree", (Standard_Integer (Convert_CompBezierCurves2dToBSplineCurve2d::*)() const) &Convert_CompBezierCurves2dToBSplineCurve2d::Degree, "Returns the degree of the BSpline curve whose data is computed in this framework. Warning Take particular care not to use this function before the computation is performed (Perform function), as this condition is not checked and an error may therefore occur.");
cls_Convert_CompBezierCurves2dToBSplineCurve2d.def("NbPoles", (Standard_Integer (Convert_CompBezierCurves2dToBSplineCurve2d::*)() const) &Convert_CompBezierCurves2dToBSplineCurve2d::NbPoles, "Returns the number of poles of the BSpline curve whose data is computed in this framework. Warning Take particular care not to use this function before the computation is performed (Perform function), as this condition is not checked and an error may therefore occur.");
cls_Convert_CompBezierCurves2dToBSplineCurve2d.def("Poles", (void (Convert_CompBezierCurves2dToBSplineCurve2d::*)(TColgp_Array1OfPnt2d &) const) &Convert_CompBezierCurves2dToBSplineCurve2d::Poles, "Loads the Poles table with the poles of the BSpline curve whose data is computed in this framework. Warning - Do not use this function before the computation is performed (Perform function). - The length of the Poles array must be equal to the number of poles of the BSpline curve whose data is computed in this framework. Particular care must be taken with respect to the above, as these conditions are not checked, and an error may occur.", py::arg("Poles"));
cls_Convert_CompBezierCurves2dToBSplineCurve2d.def("NbKnots", (Standard_Integer (Convert_CompBezierCurves2dToBSplineCurve2d::*)() const) &Convert_CompBezierCurves2dToBSplineCurve2d::NbKnots, "Returns the number of knots of the BSpline curve whose data is computed in this framework. Warning Take particular care not to use this function before the computation is performed (Perform function), as this condition is not checked and an error may therefore occur.");
cls_Convert_CompBezierCurves2dToBSplineCurve2d.def("KnotsAndMults", (void (Convert_CompBezierCurves2dToBSplineCurve2d::*)(TColStd_Array1OfReal &, TColStd_Array1OfInteger &) const) &Convert_CompBezierCurves2dToBSplineCurve2d::KnotsAndMults, "Loads the Knots table with the knots and the Mults table with the corresponding multiplicities of the BSpline curve whose data is computed in this framework. Warning - Do not use this function before the computation is performed (Perform function). - The length of the Knots and Mults arrays must be equal to the number of knots in the BSpline curve whose data is computed in this framework. Particular care must be taken with respect to the above as these conditions are not checked, and an error may occur.", py::arg("Knots"), py::arg("Mults"));

// Enums

}
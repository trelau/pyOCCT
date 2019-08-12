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
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Convert_SequenceOfArray1OfPoles.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <Convert_CompBezierCurvesToBSplineCurve.hxx>

void bind_Convert_CompBezierCurvesToBSplineCurve(py::module &mod){

py::class_<Convert_CompBezierCurvesToBSplineCurve, std::unique_ptr<Convert_CompBezierCurvesToBSplineCurve, Deleter<Convert_CompBezierCurvesToBSplineCurve>>> cls_Convert_CompBezierCurvesToBSplineCurve(mod, "Convert_CompBezierCurvesToBSplineCurve", "An algorithm to convert a sequence of adjacent non-rational Bezier curves into a BSpline curve. A CompBezierCurvesToBSplineCurve object provides a framework for: - defining the sequence of adjacent non-rational Bezier curves to be converted into a BSpline curve, - implementing the computation algorithm, and - consulting the results. Warning Do not attempt to convert rational Bezier curves using this type of algorithm.");

// Constructors
cls_Convert_CompBezierCurvesToBSplineCurve.def(py::init<>());
cls_Convert_CompBezierCurvesToBSplineCurve.def(py::init<const Standard_Real>(), py::arg("AngularTolerance"));

// Fields

// Methods
// cls_Convert_CompBezierCurvesToBSplineCurve.def_static("operator new_", (void * (*)(size_t)) &Convert_CompBezierCurvesToBSplineCurve::operator new, "None", py::arg("theSize"));
// cls_Convert_CompBezierCurvesToBSplineCurve.def_static("operator delete_", (void (*)(void *)) &Convert_CompBezierCurvesToBSplineCurve::operator delete, "None", py::arg("theAddress"));
// cls_Convert_CompBezierCurvesToBSplineCurve.def_static("operator new[]_", (void * (*)(size_t)) &Convert_CompBezierCurvesToBSplineCurve::operator new[], "None", py::arg("theSize"));
// cls_Convert_CompBezierCurvesToBSplineCurve.def_static("operator delete[]_", (void (*)(void *)) &Convert_CompBezierCurvesToBSplineCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Convert_CompBezierCurvesToBSplineCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Convert_CompBezierCurvesToBSplineCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Convert_CompBezierCurvesToBSplineCurve.def_static("operator delete_", (void (*)(void *, void *)) &Convert_CompBezierCurvesToBSplineCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_Convert_CompBezierCurvesToBSplineCurve.def("AddCurve", (void (Convert_CompBezierCurvesToBSplineCurve::*)(const TColgp_Array1OfPnt &)) &Convert_CompBezierCurvesToBSplineCurve::AddCurve, "Adds the Bezier curve defined by the table of poles Poles, to the sequence (still contained in this framework) of adjacent Bezier curves to be converted into a BSpline curve. Only polynomial (i.e. non-rational) Bezier curves are converted using this framework. If this is not the first call to the function (i.e. if this framework still contains data in its Bezier curve sequence), the degree of continuity of the BSpline curve will be increased at the time of computation at the first point of the added Bezier curve (i.e. the first point of the Poles table). This will be the case if the tangent vector of the curve at this point is parallel to the tangent vector at the end point of the preceding Bezier curve in the Bezier curve sequence still contained in this framework. An angular tolerance given at the time of construction of this framework will be used to check the parallelism of the two tangent vectors. This checking procedure and all related computations will be performed by the Perform function. When the adjacent Bezier curve sequence is complete, use the following functions: - Perform to compute the data needed to build the BSpline curve, - and the available consultation functions to access the computed data. This data may be used to construct the BSpline curve. Warning The Bezier curve sequence treated by this framework is automatically initialized with the first Bezier curve when the function is first called. During subsequent use of this function, ensure that the first point of the added Bezier curve (i.e. the first point of the Poles table) is coincident with the last point of the Bezier curve sequence (i.e. the last point of the preceding Bezier curve in the sequence) still contained in this framework. An error may occur at the time of computation if this condition is not satisfied. Particular care must be taken with respect to the above, as this condition is not checked either when defining the Bezier curve sequence or at the time of computation.", py::arg("Poles"));
cls_Convert_CompBezierCurvesToBSplineCurve.def("Perform", (void (Convert_CompBezierCurvesToBSplineCurve::*)()) &Convert_CompBezierCurvesToBSplineCurve::Perform, "Computes all the data needed to build a BSpline curve equivalent to the adjacent Bezier curve sequence still contained in this framework. A knot is inserted on the computed BSpline curve at the junction point of two consecutive Bezier curves. The degree of continuity of the BSpline curve will be increased at the junction point of two consecutive Bezier curves if their tangent vectors at this point are parallel. An angular tolerance given at the time of construction of this framework is used to check the parallelism of the two tangent vectors. Use the available consultation functions to access the computed data. This data may then be used to construct the BSpline curve. Warning Make sure that the curves in the Bezier curve sequence contained in this framework are adjacent. An error may occur at the time of computation if this condition is not satisfied. Particular care must be taken with respect to the above as this condition is not checked, either when defining the Bezier curve sequence or at the time of computation.");
cls_Convert_CompBezierCurvesToBSplineCurve.def("Degree", (Standard_Integer (Convert_CompBezierCurvesToBSplineCurve::*)() const) &Convert_CompBezierCurvesToBSplineCurve::Degree, "Returns the degree of the BSpline curve whose data is computed in this framework. Warning Take particular care not to use this function before the computation is performed (Perform function), as this condition is not checked and an error may therefore occur.");
cls_Convert_CompBezierCurvesToBSplineCurve.def("NbPoles", (Standard_Integer (Convert_CompBezierCurvesToBSplineCurve::*)() const) &Convert_CompBezierCurvesToBSplineCurve::NbPoles, "Returns the number of poles of the BSpline curve whose data is computed in this framework. Warning Take particular care not to use this function before the computation is performed (Perform function), as this condition is not checked and an error may therefore occur.");
cls_Convert_CompBezierCurvesToBSplineCurve.def("Poles", (void (Convert_CompBezierCurvesToBSplineCurve::*)(TColgp_Array1OfPnt &) const) &Convert_CompBezierCurvesToBSplineCurve::Poles, "Loads the Poles table with the poles of the BSpline curve whose data is computed in this framework. Warning - Do not use this function before the computation is performed (Perform function). - The length of the Poles array must be equal to the number of poles of the BSpline curve whose data is computed in this framework. Particular care must be taken with respect to the above, as these conditions are not checked, and an error may occur.", py::arg("Poles"));
cls_Convert_CompBezierCurvesToBSplineCurve.def("NbKnots", (Standard_Integer (Convert_CompBezierCurvesToBSplineCurve::*)() const) &Convert_CompBezierCurvesToBSplineCurve::NbKnots, "Returns the number of knots of the BSpline curve whose data is computed in this framework. Warning Take particular care not to use this function before the computation is performed (Perform function), as this condition is not checked and an error may therefore occur.");
cls_Convert_CompBezierCurvesToBSplineCurve.def("KnotsAndMults", (void (Convert_CompBezierCurvesToBSplineCurve::*)(TColStd_Array1OfReal &, TColStd_Array1OfInteger &) const) &Convert_CompBezierCurvesToBSplineCurve::KnotsAndMults, "- loads the Knots table with the knots, - and loads the Mults table with the corresponding multiplicities of the BSpline curve whose data is computed in this framework. Warning - Do not use this function before the computation is performed (Perform function). - The length of the Knots and Mults arrays must be equal to the number of knots in the BSpline curve whose data is computed in this framework. Particular care must be taken with respect to the above as these conditions are not checked, and an error may occur.", py::arg("Knots"), py::arg("Mults"));

// Enums

}
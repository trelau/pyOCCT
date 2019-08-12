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
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <GeomPlate_HArray1OfHCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom_Surface.hxx>
#include <GeomPlate_CurveConstraint.hxx>
#include <GeomPlate_PointConstraint.hxx>
#include <TColgp_SequenceOfXY.hxx>
#include <TColgp_SequenceOfXYZ.hxx>
#include <GeomPlate_Surface.hxx>
#include <TColGeom2d_HArray1OfCurve.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <Geom2d_Curve.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <GeomPlate_HArray1OfSequenceOfReal.hxx>
#include <GeomPlate_HSequenceOfCurveConstraint.hxx>
#include <GeomPlate_HSequenceOfPointConstraint.hxx>
#include <Plate_Plate.hxx>
#include <Extrema_ExtPS.hxx>
#include <GeomPlate_BuildPlateSurface.hxx>

void bind_GeomPlate_BuildPlateSurface(py::module &mod){

py::class_<GeomPlate_BuildPlateSurface, std::unique_ptr<GeomPlate_BuildPlateSurface, Deleter<GeomPlate_BuildPlateSurface>>> cls_GeomPlate_BuildPlateSurface(mod, "GeomPlate_BuildPlateSurface", "This class provides an algorithm for constructing such a plate surface that it conforms to given curve and/or point constraints. The algorithm accepts or constructs an initial surface and looks for a deformation of it satisfying the constraints and minimizing energy input. A BuildPlateSurface object provides a framework for: - defining or setting constraints - implementing the construction algorithm - consulting the result.");

// Constructors
cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<GeomPlate_HArray1OfHCurve> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const Standard_Integer>(), py::arg("NPoints"), py::arg("TabCurve"), py::arg("Tang"), py::arg("Degree"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<GeomPlate_HArray1OfHCurve> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const Standard_Integer, const Standard_Integer>(), py::arg("NPoints"), py::arg("TabCurve"), py::arg("Tang"), py::arg("Degree"), py::arg("NbIter"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<GeomPlate_HArray1OfHCurve> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("NPoints"), py::arg("TabCurve"), py::arg("Tang"), py::arg("Degree"), py::arg("NbIter"), py::arg("Tol2d"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<GeomPlate_HArray1OfHCurve> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("NPoints"), py::arg("TabCurve"), py::arg("Tang"), py::arg("Degree"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<GeomPlate_HArray1OfHCurve> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("NPoints"), py::arg("TabCurve"), py::arg("Tang"), py::arg("Degree"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<GeomPlate_HArray1OfHCurve> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("NPoints"), py::arg("TabCurve"), py::arg("Tang"), py::arg("Degree"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<GeomPlate_HArray1OfHCurve> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("NPoints"), py::arg("TabCurve"), py::arg("Tang"), py::arg("Degree"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"), py::arg("Anisotropie"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("Surf"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer>(), py::arg("Surf"), py::arg("Degree"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Integer>(), py::arg("Surf"), py::arg("Degree"), py::arg("NbPtsOnCur"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("Surf"), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Surf"), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Surf"), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surf"), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surf"), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Surf"), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"), py::arg("Anisotropie"));
cls_GeomPlate_BuildPlateSurface.def(py::init<>());
cls_GeomPlate_BuildPlateSurface.def(py::init<const Standard_Integer>(), py::arg("Degree"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"));
cls_GeomPlate_BuildPlateSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"), py::arg("Anisotropie"));

// Fields

// Methods
// cls_GeomPlate_BuildPlateSurface.def_static("operator new_", (void * (*)(size_t)) &GeomPlate_BuildPlateSurface::operator new, "None", py::arg("theSize"));
// cls_GeomPlate_BuildPlateSurface.def_static("operator delete_", (void (*)(void *)) &GeomPlate_BuildPlateSurface::operator delete, "None", py::arg("theAddress"));
// cls_GeomPlate_BuildPlateSurface.def_static("operator new[]_", (void * (*)(size_t)) &GeomPlate_BuildPlateSurface::operator new[], "None", py::arg("theSize"));
// cls_GeomPlate_BuildPlateSurface.def_static("operator delete[]_", (void (*)(void *)) &GeomPlate_BuildPlateSurface::operator delete[], "None", py::arg("theAddress"));
// cls_GeomPlate_BuildPlateSurface.def_static("operator new_", (void * (*)(size_t, void *)) &GeomPlate_BuildPlateSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomPlate_BuildPlateSurface.def_static("operator delete_", (void (*)(void *, void *)) &GeomPlate_BuildPlateSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomPlate_BuildPlateSurface.def("Init", (void (GeomPlate_BuildPlateSurface::*)()) &GeomPlate_BuildPlateSurface::Init, "Resets all constraints");
cls_GeomPlate_BuildPlateSurface.def("LoadInitSurface", (void (GeomPlate_BuildPlateSurface::*)(const opencascade::handle<Geom_Surface> &)) &GeomPlate_BuildPlateSurface::LoadInitSurface, "Loads the initial Surface", py::arg("Surf"));
cls_GeomPlate_BuildPlateSurface.def("Add", (void (GeomPlate_BuildPlateSurface::*)(const opencascade::handle<GeomPlate_CurveConstraint> &)) &GeomPlate_BuildPlateSurface::Add, "Adds the linear constraint cont.", py::arg("Cont"));
cls_GeomPlate_BuildPlateSurface.def("SetNbBounds", (void (GeomPlate_BuildPlateSurface::*)(const Standard_Integer)) &GeomPlate_BuildPlateSurface::SetNbBounds, "None", py::arg("NbBounds"));
cls_GeomPlate_BuildPlateSurface.def("Add", (void (GeomPlate_BuildPlateSurface::*)(const opencascade::handle<GeomPlate_PointConstraint> &)) &GeomPlate_BuildPlateSurface::Add, "Adds the point constraint cont.", py::arg("Cont"));
cls_GeomPlate_BuildPlateSurface.def("Perform", (void (GeomPlate_BuildPlateSurface::*)()) &GeomPlate_BuildPlateSurface::Perform, "Calls the algorithm and computes the plate surface using the loaded constraints. If no initial surface is given, the algorithm automatically computes one. Exceptions Standard_RangeError if the value of the constraint is null or if plate is not done.");
cls_GeomPlate_BuildPlateSurface.def("CurveConstraint", (opencascade::handle<GeomPlate_CurveConstraint> (GeomPlate_BuildPlateSurface::*)(const Standard_Integer) const) &GeomPlate_BuildPlateSurface::CurveConstraint, "returns the CurveConstraints of order order", py::arg("order"));
cls_GeomPlate_BuildPlateSurface.def("PointConstraint", (opencascade::handle<GeomPlate_PointConstraint> (GeomPlate_BuildPlateSurface::*)(const Standard_Integer) const) &GeomPlate_BuildPlateSurface::PointConstraint, "returns the PointConstraint of order order", py::arg("order"));
cls_GeomPlate_BuildPlateSurface.def("Disc2dContour", (void (GeomPlate_BuildPlateSurface::*)(const Standard_Integer, TColgp_SequenceOfXY &)) &GeomPlate_BuildPlateSurface::Disc2dContour, "None", py::arg("nbp"), py::arg("Seq2d"));
cls_GeomPlate_BuildPlateSurface.def("Disc3dContour", (void (GeomPlate_BuildPlateSurface::*)(const Standard_Integer, const Standard_Integer, TColgp_SequenceOfXYZ &)) &GeomPlate_BuildPlateSurface::Disc3dContour, "None", py::arg("nbp"), py::arg("iordre"), py::arg("Seq3d"));
cls_GeomPlate_BuildPlateSurface.def("IsDone", (Standard_Boolean (GeomPlate_BuildPlateSurface::*)() const) &GeomPlate_BuildPlateSurface::IsDone, "Tests whether computation of the plate has been completed.");
cls_GeomPlate_BuildPlateSurface.def("Surface", (opencascade::handle<GeomPlate_Surface> (GeomPlate_BuildPlateSurface::*)() const) &GeomPlate_BuildPlateSurface::Surface, "Returns the result of the computation. This surface can then be used by GeomPlate_MakeApprox for converting the resulting surface into a BSpline.");
cls_GeomPlate_BuildPlateSurface.def("SurfInit", (opencascade::handle<Geom_Surface> (GeomPlate_BuildPlateSurface::*)() const) &GeomPlate_BuildPlateSurface::SurfInit, "Returns the initial surface");
cls_GeomPlate_BuildPlateSurface.def("Sense", (opencascade::handle<TColStd_HArray1OfInteger> (GeomPlate_BuildPlateSurface::*)() const) &GeomPlate_BuildPlateSurface::Sense, "Allows you to ensure that the array of curves returned by Curves2d has the correct orientation. Returns the orientation of the curves in the the array returned by Curves2d. Computation changes the orientation of these curves. Consequently, this method returns the orientation prior to computation.");
cls_GeomPlate_BuildPlateSurface.def("Curves2d", (opencascade::handle<TColGeom2d_HArray1OfCurve> (GeomPlate_BuildPlateSurface::*)() const) &GeomPlate_BuildPlateSurface::Curves2d, "Extracts the array of curves on the plate surface which correspond to the curve constraints set in Add.");
cls_GeomPlate_BuildPlateSurface.def("Order", (opencascade::handle<TColStd_HArray1OfInteger> (GeomPlate_BuildPlateSurface::*)() const) &GeomPlate_BuildPlateSurface::Order, "Returns the order of the curves in the array returned by Curves2d. Computation changes this order. Consequently, this method returns the order of the curves prior to computation.");
cls_GeomPlate_BuildPlateSurface.def("G0Error", (Standard_Real (GeomPlate_BuildPlateSurface::*)() const) &GeomPlate_BuildPlateSurface::G0Error, "Returns the max distance betwen the result and the constraints");
cls_GeomPlate_BuildPlateSurface.def("G1Error", (Standard_Real (GeomPlate_BuildPlateSurface::*)() const) &GeomPlate_BuildPlateSurface::G1Error, "Returns the max angle betwen the result and the constraints");
cls_GeomPlate_BuildPlateSurface.def("G2Error", (Standard_Real (GeomPlate_BuildPlateSurface::*)() const) &GeomPlate_BuildPlateSurface::G2Error, "Returns the max difference of curvature betwen the result and the constraints");
cls_GeomPlate_BuildPlateSurface.def("G0Error", (Standard_Real (GeomPlate_BuildPlateSurface::*)(const Standard_Integer)) &GeomPlate_BuildPlateSurface::G0Error, "Returns the max distance between the result and the constraint Index", py::arg("Index"));
cls_GeomPlate_BuildPlateSurface.def("G1Error", (Standard_Real (GeomPlate_BuildPlateSurface::*)(const Standard_Integer)) &GeomPlate_BuildPlateSurface::G1Error, "Returns the max angle between the result and the constraint Index", py::arg("Index"));
cls_GeomPlate_BuildPlateSurface.def("G2Error", (Standard_Real (GeomPlate_BuildPlateSurface::*)(const Standard_Integer)) &GeomPlate_BuildPlateSurface::G2Error, "Returns the max difference of curvature between the result and the constraint Index", py::arg("Index"));

// Enums

}
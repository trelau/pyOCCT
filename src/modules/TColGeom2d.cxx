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
#include <NCollection_Array1.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <TColGeom2d_Array1OfCurve.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Std.hxx>
#include <TColGeom2d_HArray1OfCurve.hxx>
#include <Standard_Type.hxx>
#include <NCollection_Sequence.hxx>
#include <TColGeom2d_SequenceOfCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <TColGeom2d_Array1OfBSplineCurve.hxx>
#include <TColGeom2d_HArray1OfBSplineCurve.hxx>
#include <Geom2d_BezierCurve.hxx>
#include <TColGeom2d_Array1OfBezierCurve.hxx>
#include <Geom2d_Geometry.hxx>
#include <TColGeom2d_SequenceOfGeometry.hxx>
#include <Geom2d_BoundedCurve.hxx>
#include <TColGeom2d_SequenceOfBoundedCurve.hxx>
#include <TColGeom2d_HSequenceOfBoundedCurve.hxx>
#include <TColGeom2d_HSequenceOfCurve.hxx>
#include <TColGeom2d_HArray1OfBezierCurve.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_Define_HArray1.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_Define_HSequence.hxx>

PYBIND11_MODULE(TColGeom2d, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom2d");

// TYPEDEF: TCOLGEOM2D_ARRAY1OFCURVE
bind_NCollection_Array1<opencascade::handle<Geom2d_Curve> >(mod, "TColGeom2d_Array1OfCurve", py::module_local(false));

// CLASS: TCOLGEOM2D_HARRAY1OFCURVE
bind_Define_HArray1<TColGeom2d_HArray1OfCurve, TColGeom2d_Array1OfCurve>(mod, "TColGeom2d_HArray1OfCurve");

// TYPEDEF: TCOLGEOM2D_SEQUENCEOFCURVE
bind_NCollection_Sequence<opencascade::handle<Geom2d_Curve> >(mod, "TColGeom2d_SequenceOfCurve", py::module_local(false));

// TYPEDEF: TCOLGEOM2D_ARRAY1OFBSPLINECURVE
bind_NCollection_Array1<opencascade::handle<Geom2d_BSplineCurve> >(mod, "TColGeom2d_Array1OfBSplineCurve", py::module_local(false));

// CLASS: TCOLGEOM2D_HARRAY1OFBSPLINECURVE
bind_Define_HArray1<TColGeom2d_HArray1OfBSplineCurve, TColGeom2d_Array1OfBSplineCurve>(mod, "TColGeom2d_HArray1OfBSplineCurve");

// TYPEDEF: TCOLGEOM2D_ARRAY1OFBEZIERCURVE
bind_NCollection_Array1<opencascade::handle<Geom2d_BezierCurve> >(mod, "TColGeom2d_Array1OfBezierCurve", py::module_local(false));

// TYPEDEF: TCOLGEOM2D_SEQUENCEOFGEOMETRY
bind_NCollection_Sequence<opencascade::handle<Geom2d_Geometry> >(mod, "TColGeom2d_SequenceOfGeometry", py::module_local(false));

// TYPEDEF: TCOLGEOM2D_SEQUENCEOFBOUNDEDCURVE
bind_NCollection_Sequence<opencascade::handle<Geom2d_BoundedCurve> >(mod, "TColGeom2d_SequenceOfBoundedCurve", py::module_local(false));

// CLASS: TCOLGEOM2D_HSEQUENCEOFBOUNDEDCURVE
bind_Define_HSequence<TColGeom2d_HSequenceOfBoundedCurve, TColGeom2d_SequenceOfBoundedCurve>(mod, "TColGeom2d_HSequenceOfBoundedCurve");

// CLASS: TCOLGEOM2D_HSEQUENCEOFCURVE
bind_Define_HSequence<TColGeom2d_HSequenceOfCurve, TColGeom2d_SequenceOfCurve>(mod, "TColGeom2d_HSequenceOfCurve");

// CLASS: TCOLGEOM2D_HARRAY1OFBEZIERCURVE
bind_Define_HArray1<TColGeom2d_HArray1OfBezierCurve, TColGeom2d_Array1OfBezierCurve>(mod, "TColGeom2d_HArray1OfBezierCurve");


}

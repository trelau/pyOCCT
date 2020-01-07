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
#include <Geom_Surface.hxx>
#include <TColGeom_Array1OfSurface.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Std.hxx>
#include <TColGeom_HArray1OfSurface.hxx>
#include <Standard_Type.hxx>
#include <NCollection_Sequence.hxx>
#include <Geom_Curve.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <TColGeom_Array1OfBSplineCurve.hxx>
#include <TColGeom_HArray1OfBSplineCurve.hxx>
#include <Geom_BezierCurve.hxx>
#include <TColGeom_Array1OfBezierCurve.hxx>
#include <NCollection_Array2.hxx>
#include <Geom_BezierSurface.hxx>
#include <TColGeom_Array2OfBezierSurface.hxx>
#include <Geom_BoundedCurve.hxx>
#include <TColGeom_SequenceOfBoundedCurve.hxx>
#include <TColGeom_HSequenceOfBoundedCurve.hxx>
#include <TColGeom_Array2OfSurface.hxx>
#include <TColGeom_HArray2OfSurface.hxx>
#include <TColGeom_HSequenceOfCurve.hxx>
#include <TColGeom_Array1OfCurve.hxx>
#include <TColGeom_HArray1OfCurve.hxx>
#include <TColGeom_HArray1OfBezierCurve.hxx>
#include <TColGeom_SequenceOfSurface.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_Define_HArray1.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_NCollection_Array2.hxx>
#include <bind_Define_HSequence.hxx>
#include <bind_Define_HArray2.hxx>

PYBIND11_MODULE(TColGeom, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom");

// TYPEDEF: TCOLGEOM_ARRAY1OFSURFACE
bind_NCollection_Array1<opencascade::handle<Geom_Surface> >(mod, "TColGeom_Array1OfSurface", py::module_local(false));

// CLASS: TCOLGEOM_HARRAY1OFSURFACE
bind_Define_HArray1<TColGeom_HArray1OfSurface, TColGeom_Array1OfSurface>(mod, "TColGeom_HArray1OfSurface");

// TYPEDEF: TCOLGEOM_SEQUENCEOFCURVE
bind_NCollection_Sequence<opencascade::handle<Geom_Curve> >(mod, "TColGeom_SequenceOfCurve", py::module_local(false));

// TYPEDEF: TCOLGEOM_ARRAY1OFBSPLINECURVE
bind_NCollection_Array1<opencascade::handle<Geom_BSplineCurve> >(mod, "TColGeom_Array1OfBSplineCurve", py::module_local(false));

// CLASS: TCOLGEOM_HARRAY1OFBSPLINECURVE
bind_Define_HArray1<TColGeom_HArray1OfBSplineCurve, TColGeom_Array1OfBSplineCurve>(mod, "TColGeom_HArray1OfBSplineCurve");

// TYPEDEF: TCOLGEOM_ARRAY1OFBEZIERCURVE
bind_NCollection_Array1<opencascade::handle<Geom_BezierCurve> >(mod, "TColGeom_Array1OfBezierCurve", py::module_local(false));

// TYPEDEF: TCOLGEOM_ARRAY2OFBEZIERSURFACE
bind_NCollection_Array2<opencascade::handle<Geom_BezierSurface> >(mod, "TColGeom_Array2OfBezierSurface", py::module_local(false));

// TYPEDEF: TCOLGEOM_SEQUENCEOFBOUNDEDCURVE
bind_NCollection_Sequence<opencascade::handle<Geom_BoundedCurve> >(mod, "TColGeom_SequenceOfBoundedCurve", py::module_local(false));

// CLASS: TCOLGEOM_HSEQUENCEOFBOUNDEDCURVE
bind_Define_HSequence<TColGeom_HSequenceOfBoundedCurve, TColGeom_SequenceOfBoundedCurve>(mod, "TColGeom_HSequenceOfBoundedCurve");

// TYPEDEF: TCOLGEOM_ARRAY2OFSURFACE
bind_NCollection_Array2<opencascade::handle<Geom_Surface> >(mod, "TColGeom_Array2OfSurface", py::module_local(false));

// CLASS: TCOLGEOM_HARRAY2OFSURFACE
bind_Define_HArray2<TColGeom_HArray2OfSurface, TColGeom_Array2OfSurface>(mod, "TColGeom_HArray2OfSurface");

// CLASS: TCOLGEOM_HSEQUENCEOFCURVE
bind_Define_HSequence<TColGeom_HSequenceOfCurve, TColGeom_SequenceOfCurve>(mod, "TColGeom_HSequenceOfCurve");

// TYPEDEF: TCOLGEOM_ARRAY1OFCURVE
bind_NCollection_Array1<opencascade::handle<Geom_Curve> >(mod, "TColGeom_Array1OfCurve", py::module_local(false));

// CLASS: TCOLGEOM_HARRAY1OFCURVE
bind_Define_HArray1<TColGeom_HArray1OfCurve, TColGeom_Array1OfCurve>(mod, "TColGeom_HArray1OfCurve");

// CLASS: TCOLGEOM_HARRAY1OFBEZIERCURVE
bind_Define_HArray1<TColGeom_HArray1OfBezierCurve, TColGeom_Array1OfBezierCurve>(mod, "TColGeom_HArray1OfBezierCurve");

// TYPEDEF: TCOLGEOM_SEQUENCEOFSURFACE
bind_NCollection_Sequence<opencascade::handle<Geom_Surface> >(mod, "TColGeom_SequenceOfSurface", py::module_local(false));


}

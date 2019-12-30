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
#include <gp_Pnt2d.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Std.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <Standard_Type.hxx>
#include <gp_Pnt.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <NCollection_Array2.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <TColgp_Array2OfPnt2d.hxx>
#include <TColgp_HArray2OfPnt2d.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <NCollection_Sequence.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <TColgp_HSequenceOfPnt.hxx>
#include <gp_Dir.hxx>
#include <TColgp_Array1OfDir.hxx>
#include <TColgp_HArray1OfDir.hxx>
#include <gp_Vec.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_HArray1OfVec.hxx>
#include <gp_Vec2d.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <TColgp_HArray1OfVec2d.hxx>
#include <TColgp_SequenceOfArray1OfPnt2d.hxx>
#include <gp_XYZ.hxx>
#include <TColgp_Array2OfXYZ.hxx>
#include <TColgp_HArray2OfXYZ.hxx>
#include <TColgp_Array1OfXYZ.hxx>
#include <gp_XY.hxx>
#include <TColgp_SequenceOfXY.hxx>
#include <TColgp_SequenceOfXYZ.hxx>
#include <TColgp_SequenceOfPnt2d.hxx>
#include <gp_Ax1.hxx>
#include <TColgp_SequenceOfAx1.hxx>
#include <TColgp_HSequenceOfXY.hxx>
#include <TColgp_Array2OfVec.hxx>
#include <TColgp_Array1OfXY.hxx>
#include <gp_Circ2d.hxx>
#include <TColgp_Array1OfCirc2d.hxx>
#include <gp_Lin2d.hxx>
#include <TColgp_Array1OfLin2d.hxx>
#include <TColgp_SequenceOfVec.hxx>
#include <TColgp_HArray1OfXYZ.hxx>
#include <TColgp_HArray1OfXY.hxx>
#include <TColgp_HSequenceOfXYZ.hxx>
#include <gp_Dir2d.hxx>
#include <TColgp_Array1OfDir2d.hxx>
#include <TColgp_HArray1OfDir2d.hxx>
#include <TColgp_HArray1OfLin2d.hxx>
#include <TColgp_HArray1OfCirc2d.hxx>
#include <TColgp_Array2OfDir.hxx>
#include <TColgp_HArray2OfDir.hxx>
#include <TColgp_HArray2OfVec.hxx>
#include <TColgp_Array2OfXY.hxx>
#include <TColgp_HArray2OfXY.hxx>
#include <TColgp_Array2OfDir2d.hxx>
#include <TColgp_HArray2OfDir2d.hxx>
#include <TColgp_Array2OfVec2d.hxx>
#include <TColgp_HArray2OfVec2d.hxx>
#include <TColgp_Array2OfLin2d.hxx>
#include <TColgp_HArray2OfLin2d.hxx>
#include <TColgp_Array2OfCirc2d.hxx>
#include <TColgp_HArray2OfCirc2d.hxx>
#include <TColgp_SequenceOfDir.hxx>
#include <TColgp_HSequenceOfDir.hxx>
#include <TColgp_HSequenceOfVec.hxx>
#include <TColgp_SequenceOfDir2d.hxx>
#include <TColgp_HSequenceOfDir2d.hxx>
#include <TColgp_HSequenceOfPnt2d.hxx>
#include <TColgp_SequenceOfVec2d.hxx>
#include <TColgp_HSequenceOfVec2d.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_Define_HArray1.hxx>
#include <bind_NCollection_Array2.hxx>
#include <bind_Define_HArray2.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_Define_HSequence.hxx>

PYBIND11_MODULE(TColgp, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.Standard");

// TYPEDEF: TCOLGP_ARRAY1OFPNT2D
bind_NCollection_Array1<gp_Pnt2d>(mod, "TColgp_Array1OfPnt2d", py::module_local(false));

// CLASS: TCOLGP_HARRAY1OFPNT2D
bind_Define_HArray1<TColgp_HArray1OfPnt2d, TColgp_Array1OfPnt2d>(mod, "TColgp_HArray1OfPnt2d");

// TYPEDEF: TCOLGP_ARRAY1OFPNT
bind_NCollection_Array1<gp_Pnt>(mod, "TColgp_Array1OfPnt", py::module_local(false));

// TYPEDEF: TCOLGP_ARRAY2OFPNT
bind_NCollection_Array2<gp_Pnt>(mod, "TColgp_Array2OfPnt", py::module_local(false));

// CLASS: TCOLGP_HARRAY2OFPNT
bind_Define_HArray2<TColgp_HArray2OfPnt, TColgp_Array2OfPnt>(mod, "TColgp_HArray2OfPnt");

// TYPEDEF: TCOLGP_ARRAY2OFPNT2D
bind_NCollection_Array2<gp_Pnt2d>(mod, "TColgp_Array2OfPnt2d", py::module_local(false));

// CLASS: TCOLGP_HARRAY2OFPNT2D
bind_Define_HArray2<TColgp_HArray2OfPnt2d, TColgp_Array2OfPnt2d>(mod, "TColgp_HArray2OfPnt2d");

// CLASS: TCOLGP_HARRAY1OFPNT
bind_Define_HArray1<TColgp_HArray1OfPnt, TColgp_Array1OfPnt>(mod, "TColgp_HArray1OfPnt");

// TYPEDEF: TCOLGP_SEQUENCEOFPNT
bind_NCollection_Sequence<gp_Pnt>(mod, "TColgp_SequenceOfPnt", py::module_local(false));

// CLASS: TCOLGP_HSEQUENCEOFPNT
bind_Define_HSequence<TColgp_HSequenceOfPnt, TColgp_SequenceOfPnt>(mod, "TColgp_HSequenceOfPnt");

// TYPEDEF: TCOLGP_ARRAY1OFDIR
bind_NCollection_Array1<gp_Dir>(mod, "TColgp_Array1OfDir", py::module_local(false));

// CLASS: TCOLGP_HARRAY1OFDIR
bind_Define_HArray1<TColgp_HArray1OfDir, TColgp_Array1OfDir>(mod, "TColgp_HArray1OfDir");

// TYPEDEF: TCOLGP_ARRAY1OFVEC
bind_NCollection_Array1<gp_Vec>(mod, "TColgp_Array1OfVec", py::module_local(false));

// CLASS: TCOLGP_HARRAY1OFVEC
bind_Define_HArray1<TColgp_HArray1OfVec, TColgp_Array1OfVec>(mod, "TColgp_HArray1OfVec");

// TYPEDEF: TCOLGP_ARRAY1OFVEC2D
bind_NCollection_Array1<gp_Vec2d>(mod, "TColgp_Array1OfVec2d", py::module_local(false));

// CLASS: TCOLGP_HARRAY1OFVEC2D
bind_Define_HArray1<TColgp_HArray1OfVec2d, TColgp_Array1OfVec2d>(mod, "TColgp_HArray1OfVec2d");

// TYPEDEF: TCOLGP_SEQUENCEOFARRAY1OFPNT2D
bind_NCollection_Sequence<opencascade::handle<TColgp_HArray1OfPnt2d> >(mod, "TColgp_SequenceOfArray1OfPnt2d", py::module_local(false));

// TYPEDEF: TCOLGP_ARRAY2OFXYZ
bind_NCollection_Array2<gp_XYZ>(mod, "TColgp_Array2OfXYZ", py::module_local(false));

// CLASS: TCOLGP_HARRAY2OFXYZ
bind_Define_HArray2<TColgp_HArray2OfXYZ, TColgp_Array2OfXYZ>(mod, "TColgp_HArray2OfXYZ");

// TYPEDEF: TCOLGP_ARRAY1OFXYZ
bind_NCollection_Array1<gp_XYZ>(mod, "TColgp_Array1OfXYZ", py::module_local(false));

// TYPEDEF: TCOLGP_SEQUENCEOFXY
bind_NCollection_Sequence<gp_XY>(mod, "TColgp_SequenceOfXY", py::module_local(false));

// TYPEDEF: TCOLGP_SEQUENCEOFXYZ
bind_NCollection_Sequence<gp_XYZ>(mod, "TColgp_SequenceOfXYZ", py::module_local(false));

// TYPEDEF: TCOLGP_SEQUENCEOFPNT2D
bind_NCollection_Sequence<gp_Pnt2d>(mod, "TColgp_SequenceOfPnt2d", py::module_local(false));

// TYPEDEF: TCOLGP_SEQUENCEOFAX1
bind_NCollection_Sequence<gp_Ax1>(mod, "TColgp_SequenceOfAx1", py::module_local(false));

// CLASS: TCOLGP_HSEQUENCEOFXY
bind_Define_HSequence<TColgp_HSequenceOfXY, TColgp_SequenceOfXY>(mod, "TColgp_HSequenceOfXY");

// TYPEDEF: TCOLGP_ARRAY2OFVEC
bind_NCollection_Array2<gp_Vec>(mod, "TColgp_Array2OfVec", py::module_local(false));

// TYPEDEF: TCOLGP_ARRAY1OFXY
bind_NCollection_Array1<gp_XY>(mod, "TColgp_Array1OfXY", py::module_local(false));

// TYPEDEF: TCOLGP_ARRAY1OFCIRC2D
bind_NCollection_Array1<gp_Circ2d>(mod, "TColgp_Array1OfCirc2d", py::module_local(false));

// TYPEDEF: TCOLGP_ARRAY1OFLIN2D
bind_NCollection_Array1<gp_Lin2d>(mod, "TColgp_Array1OfLin2d", py::module_local(false));

// TYPEDEF: TCOLGP_SEQUENCEOFVEC
bind_NCollection_Sequence<gp_Vec>(mod, "TColgp_SequenceOfVec", py::module_local(false));

// CLASS: TCOLGP_HARRAY1OFXYZ
bind_Define_HArray1<TColgp_HArray1OfXYZ, TColgp_Array1OfXYZ>(mod, "TColgp_HArray1OfXYZ");

// CLASS: TCOLGP_HARRAY1OFXY
bind_Define_HArray1<TColgp_HArray1OfXY, TColgp_Array1OfXY>(mod, "TColgp_HArray1OfXY");

// CLASS: TCOLGP_HSEQUENCEOFXYZ
bind_Define_HSequence<TColgp_HSequenceOfXYZ, TColgp_SequenceOfXYZ>(mod, "TColgp_HSequenceOfXYZ");

// TYPEDEF: TCOLGP_ARRAY1OFDIR2D
bind_NCollection_Array1<gp_Dir2d>(mod, "TColgp_Array1OfDir2d", py::module_local(false));

// CLASS: TCOLGP_HARRAY1OFDIR2D
bind_Define_HArray1<TColgp_HArray1OfDir2d, TColgp_Array1OfDir2d>(mod, "TColgp_HArray1OfDir2d");

// CLASS: TCOLGP_HARRAY1OFLIN2D
bind_Define_HArray1<TColgp_HArray1OfLin2d, TColgp_Array1OfLin2d>(mod, "TColgp_HArray1OfLin2d");

// CLASS: TCOLGP_HARRAY1OFCIRC2D
bind_Define_HArray1<TColgp_HArray1OfCirc2d, TColgp_Array1OfCirc2d>(mod, "TColgp_HArray1OfCirc2d");

// TYPEDEF: TCOLGP_ARRAY2OFDIR
bind_NCollection_Array2<gp_Dir>(mod, "TColgp_Array2OfDir", py::module_local(false));

// CLASS: TCOLGP_HARRAY2OFDIR
bind_Define_HArray2<TColgp_HArray2OfDir, TColgp_Array2OfDir>(mod, "TColgp_HArray2OfDir");

// CLASS: TCOLGP_HARRAY2OFVEC
bind_Define_HArray2<TColgp_HArray2OfVec, TColgp_Array2OfVec>(mod, "TColgp_HArray2OfVec");

// TYPEDEF: TCOLGP_ARRAY2OFXY
bind_NCollection_Array2<gp_XY>(mod, "TColgp_Array2OfXY", py::module_local(false));

// CLASS: TCOLGP_HARRAY2OFXY
bind_Define_HArray2<TColgp_HArray2OfXY, TColgp_Array2OfXY>(mod, "TColgp_HArray2OfXY");

// TYPEDEF: TCOLGP_ARRAY2OFDIR2D
bind_NCollection_Array2<gp_Dir2d>(mod, "TColgp_Array2OfDir2d", py::module_local(false));

// CLASS: TCOLGP_HARRAY2OFDIR2D
bind_Define_HArray2<TColgp_HArray2OfDir2d, TColgp_Array2OfDir2d>(mod, "TColgp_HArray2OfDir2d");

// TYPEDEF: TCOLGP_ARRAY2OFVEC2D
bind_NCollection_Array2<gp_Vec2d>(mod, "TColgp_Array2OfVec2d", py::module_local(false));

// CLASS: TCOLGP_HARRAY2OFVEC2D
bind_Define_HArray2<TColgp_HArray2OfVec2d, TColgp_Array2OfVec2d>(mod, "TColgp_HArray2OfVec2d");

// TYPEDEF: TCOLGP_ARRAY2OFLIN2D
bind_NCollection_Array2<gp_Lin2d>(mod, "TColgp_Array2OfLin2d", py::module_local(false));

// CLASS: TCOLGP_HARRAY2OFLIN2D
bind_Define_HArray2<TColgp_HArray2OfLin2d, TColgp_Array2OfLin2d>(mod, "TColgp_HArray2OfLin2d");

// TYPEDEF: TCOLGP_ARRAY2OFCIRC2D
bind_NCollection_Array2<gp_Circ2d>(mod, "TColgp_Array2OfCirc2d", py::module_local(false));

// CLASS: TCOLGP_HARRAY2OFCIRC2D
bind_Define_HArray2<TColgp_HArray2OfCirc2d, TColgp_Array2OfCirc2d>(mod, "TColgp_HArray2OfCirc2d");

// TYPEDEF: TCOLGP_SEQUENCEOFDIR
bind_NCollection_Sequence<gp_Dir>(mod, "TColgp_SequenceOfDir", py::module_local(false));

// CLASS: TCOLGP_HSEQUENCEOFDIR
bind_Define_HSequence<TColgp_HSequenceOfDir, TColgp_SequenceOfDir>(mod, "TColgp_HSequenceOfDir");

// CLASS: TCOLGP_HSEQUENCEOFVEC
bind_Define_HSequence<TColgp_HSequenceOfVec, TColgp_SequenceOfVec>(mod, "TColgp_HSequenceOfVec");

// TYPEDEF: TCOLGP_SEQUENCEOFDIR2D
bind_NCollection_Sequence<gp_Dir2d>(mod, "TColgp_SequenceOfDir2d", py::module_local(false));

// CLASS: TCOLGP_HSEQUENCEOFDIR2D
bind_Define_HSequence<TColgp_HSequenceOfDir2d, TColgp_SequenceOfDir2d>(mod, "TColgp_HSequenceOfDir2d");

// CLASS: TCOLGP_HSEQUENCEOFPNT2D
bind_Define_HSequence<TColgp_HSequenceOfPnt2d, TColgp_SequenceOfPnt2d>(mod, "TColgp_HSequenceOfPnt2d");

// TYPEDEF: TCOLGP_SEQUENCEOFVEC2D
bind_NCollection_Sequence<gp_Vec2d>(mod, "TColgp_SequenceOfVec2d", py::module_local(false));

// CLASS: TCOLGP_HSEQUENCEOFVEC2D
bind_Define_HSequence<TColgp_HSequenceOfVec2d, TColgp_SequenceOfVec2d>(mod, "TColgp_HSequenceOfVec2d");


}

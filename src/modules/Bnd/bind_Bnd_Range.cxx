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
#include <Standard_TypeDef.hxx>
#include <Standard_ConstructionError.hxx>
#include <Bnd_Range.hxx>
#include <NCollection_List.hxx>

void bind_Bnd_Range(py::module &mod){

py::class_<Bnd_Range, std::unique_ptr<Bnd_Range>> cls_Bnd_Range(mod, "Bnd_Range", "This class describes a range in 1D space restricted by two real values. A range can be void indicating there is no point included in the range.");

// Constructors
cls_Bnd_Range.def(py::init<>());
cls_Bnd_Range.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("theMin"), py::arg("theMax"));

// Fields

// Methods
cls_Bnd_Range.def("Common", (void (Bnd_Range::*)(const Bnd_Range &)) &Bnd_Range::Common, "Replaces <this> with common-part of <this> and theOther", py::arg("theOther"));
cls_Bnd_Range.def("Union", (Standard_Boolean (Bnd_Range::*)(const Bnd_Range &)) &Bnd_Range::Union, "Joins *this and theOther to one interval. Replaces *this to the result. Returns false if the operation cannot be done (e.g. input arguments are empty or separated).", py::arg("theOther"));
cls_Bnd_Range.def("Split", [](Bnd_Range &self, const Standard_Real a0, NCollection_List<Bnd_Range> & a1) -> void { return self.Split(a0, a1); });
cls_Bnd_Range.def("Split", (void (Bnd_Range::*)(const Standard_Real, NCollection_List<Bnd_Range> &, const Standard_Real) const) &Bnd_Range::Split, "Splits <this> to several sub-ranges by theVal value (e.g. range [3, 15] will be split by theVal==5 to the two ranges: [3, 5] and [5, 15]). New ranges will be pushed to theList (theList must be initialized correctly before calling this method). If thePeriod != 0.0 then at least one boundary of new ranges (if <*this> intersects theVal+k*thePeriod) will be equal to theVal+thePeriod*k, where k is an integer number (k = 0, +/-1, +/-2, ...). (let thePeriod in above example be 4 ==> we will obtain four ranges: [3, 5], [5, 9], [9, 13] and [13, 15].", py::arg("theVal"), py::arg("theList"), py::arg("thePeriod"));
cls_Bnd_Range.def("IsIntersected", [](Bnd_Range &self, const Standard_Real a0) -> Standard_Integer { return self.IsIntersected(a0); });
cls_Bnd_Range.def("IsIntersected", (Standard_Integer (Bnd_Range::*)(const Standard_Real, const Standard_Real) const) &Bnd_Range::IsIntersected, "Checks if <this> intersects values like theVal+k*thePeriod, where k is an integer number (k = 0, +/-1, +/-2, ...). Returns: 0 - if <this> does not intersect the theVal+k*thePeriod. 1 - if <this> intersects theVal+k*thePeriod. 2 - if myFirst or/and myLast are equal to theVal+k*thePeriod.", py::arg("theVal"), py::arg("thePeriod"));
cls_Bnd_Range.def("Add", (void (Bnd_Range::*)(const Standard_Real)) &Bnd_Range::Add, "Extends <this> to include theParameter", py::arg("theParameter"));
cls_Bnd_Range.def("Add", (void (Bnd_Range::*)(const Bnd_Range &)) &Bnd_Range::Add, "Extends this range to include both ranges.", py::arg("theRange"));
cls_Bnd_Range.def("GetMin", [](Bnd_Range &self, Standard_Real & thePar){ Standard_Boolean rv = self.GetMin(thePar); return std::tuple<Standard_Boolean, Standard_Real &>(rv, thePar); }, "Obtain MIN boundary of <this>. If <this> is VOID the method returns false.", py::arg("thePar"));
cls_Bnd_Range.def("GetMax", [](Bnd_Range &self, Standard_Real & thePar){ Standard_Boolean rv = self.GetMax(thePar); return std::tuple<Standard_Boolean, Standard_Real &>(rv, thePar); }, "Obtain MAX boundary of <this>. If <this> is VOID the method returns false.", py::arg("thePar"));
cls_Bnd_Range.def("GetBounds", [](Bnd_Range &self, Standard_Real & theFirstPar, Standard_Real & theLastPar){ Standard_Boolean rv = self.GetBounds(theFirstPar, theLastPar); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, theFirstPar, theLastPar); }, "Obtain first and last boundary of <this>. If <this> is VOID the method returns false.", py::arg("theFirstPar"), py::arg("theLastPar"));
cls_Bnd_Range.def("Delta", (Standard_Real (Bnd_Range::*)() const) &Bnd_Range::Delta, "Returns range value (MAX-MIN). Returns negative value for VOID range.");
cls_Bnd_Range.def("IsVoid", (Standard_Boolean (Bnd_Range::*)() const) &Bnd_Range::IsVoid, "Is <this> initialized.");
cls_Bnd_Range.def("SetVoid", (void (Bnd_Range::*)()) &Bnd_Range::SetVoid, "Initializes <this> by default parameters. Makes <this> VOID.");
cls_Bnd_Range.def("Enlarge", (void (Bnd_Range::*)(const Standard_Real)) &Bnd_Range::Enlarge, "Extends this to the given value (in both side)", py::arg("theDelta"));
cls_Bnd_Range.def("Shifted", (Bnd_Range (Bnd_Range::*)(const Standard_Real) const) &Bnd_Range::Shifted, "Returns the copy of <*this> shifted by theVal", py::arg("theVal"));
cls_Bnd_Range.def("Shift", (void (Bnd_Range::*)(const Standard_Real)) &Bnd_Range::Shift, "Shifts <*this> by theVal", py::arg("theVal"));
cls_Bnd_Range.def("IsOut", (Standard_Boolean (Bnd_Range::*)(Standard_Real) const) &Bnd_Range::IsOut, "Returns True if the value is out of this range.", py::arg("theValue"));
cls_Bnd_Range.def("IsOut", (Standard_Boolean (Bnd_Range::*)(const Bnd_Range &) const) &Bnd_Range::IsOut, "Returns True if the given range is out of this range.", py::arg("theRange"));
cls_Bnd_Range.def("__eq__", (Standard_Boolean (Bnd_Range::*)(const Bnd_Range &) const) &Bnd_Range::operator==, py::is_operator(), "Returns TRUE if theOther is equal to <*this>", py::arg("theOther"));

// Enums

}
/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2021  Trevor Laughlin and the pyOCCT contributors

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
#pragma once

#include <pyOCCT_Common.hxx>
#include <AIS_InteractiveObject.hxx>
#include <AIS_KindOfInteractive.hxx>


class AIS_PyInteractiveObject: public AIS_InteractiveObject {
    DEFINE_STANDARD_RTTIEXT(AIS_PyInteractiveObject, AIS_InteractiveObject)
public:
    //! Empty constructor
    AIS_PyInteractiveObject() {};
    void Compute (const Handle(PrsMgr_PresentationManager3d)& aPresentationManager, const Handle(Prs3d_Presentation)& aPresentation, const Standard_Integer aMode = 0) Standard_OVERRIDE {
        PYBIND11_OVERRIDE_PURE(void, AIS_InteractiveObject, Compute, aPresentationManager, aPresentation, aMode);
    }
    void ComputeSelection (const Handle(SelectMgr_Selection)& aSelection, const Standard_Integer aMode) Standard_OVERRIDE {
        PYBIND11_OVERRIDE_PURE(void, AIS_InteractiveObject, ComputeSelection, aSelection, aMode);
    }
    Standard_Integer Signature() const Standard_OVERRIDE {
        PYBIND11_OVERRIDE(Standard_Integer, AIS_InteractiveObject, Signature);
    }
    AIS_KindOfInteractive Type() const Standard_OVERRIDE {
        PYBIND11_OVERRIDE(AIS_KindOfInteractive, AIS_InteractiveObject, Type);
    }

    virtual ~AIS_PyInteractiveObject() {};
};

DEFINE_STANDARD_HANDLE(AIS_PyInteractiveObject, AIS_InteractiveObject)
IMPLEMENT_STANDARD_RTTIEXT(AIS_PyInteractiveObject, AIS_InteractiveObject)

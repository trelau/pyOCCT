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
#include <Standard_HandlerStatus.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Real.hxx>
#include <Standard_ShortReal.hxx>
#include <Standard_Address.hxx>
#include <Standard_Size.hxx>
#include <Standard_CString.hxx>
#include <Standard_Transient.hxx>
#include <Standard_ThreadId.hxx>
#include <Standard_Character.hxx>
#include <Standard_ExtCharacter.hxx>
#include <Standard_Time.hxx>
#include <Standard_Assert.hxx>
#include <Standard_Atomic.hxx>
#include <Standard.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Failure.hxx>
#include <Standard_DomainError.hxx>
#include <Standard_DimensionError.hxx>
#include <Standard_DimensionMismatch.hxx>
#include <Standard_ProgramError.hxx>
#include <Standard_OutOfMemory.hxx>
#include <Standard_RangeError.hxx>
#include <Standard_OutOfRange.hxx>
#include <Standard_ConstructionError.hxx>
#include <Standard_NoSuchObject.hxx>
#include <Standard_PCharacter.hxx>
#include <Standard_IStream.hxx>
#include <Standard_PExtCharacter.hxx>
#include <Standard_TypeMismatch.hxx>
#include <Standard_Persistent.hxx>
#include <Standard_UUID.hxx>
#include <Standard_GUID.hxx>
#include <Standard_MultiplyDefined.hxx>
#include <Standard_ImmutableObject.hxx>
#include <Standard_ErrorHandler.hxx>
#include <Standard_PErrorHandler.hxx>
#include <Standard_JmpBuf.hxx>
#include <Standard_Mutex.hxx>
#include <Standard_NullObject.hxx>
#include <Standard_NotImplemented.hxx>
#include <Standard_NegativeValue.hxx>
#include <Standard_NullValue.hxx>
#include <Standard_AbortiveTransaction.hxx>
#include <Standard_ArrayStreamBuffer.hxx>
#include <Standard_CLocaleSentry.hxx>
#include <Standard_NumericError.hxx>
#include <Standard_DivideByZero.hxx>
#include <Standard_LicenseError.hxx>
#include <Standard_LicenseNotFound.hxx>
#include <Standard_MMgrRoot.hxx>
#include <Standard_MMgrOpt.hxx>
#include <Standard_MMgrRaw.hxx>
#include <Standard_MMgrTBBalloc.hxx>
#include <Standard_NoMoreObject.hxx>
#include <Standard_Overflow.hxx>
#include <Standard_PByte.hxx>
#include <Standard_TooManyUsers.hxx>
#include <Standard_Underflow.hxx>

PYBIND11_MODULE(Standard, mod) {


// ENUM: STANDARD_HANDLERSTATUS
py::enum_<Standard_HandlerStatus>(mod, "Standard_HandlerStatus", "None")
	.value("Standard_HandlerVoid", Standard_HandlerStatus::Standard_HandlerVoid)
	.value("Standard_HandlerJumped", Standard_HandlerStatus::Standard_HandlerJumped)
	.value("Standard_HandlerProcessed", Standard_HandlerStatus::Standard_HandlerProcessed)
	.export_values();


// FUNCTION: ABS
mod.def("Abs", (Standard_Integer (*) (const Standard_Integer)) &Abs, "None", py::arg("Value"));

mod.def("Abs", (Standard_Real (*) (const Standard_Real)) &Abs, "None", py::arg("Value"));

mod.def("Abs", (Standard_ShortReal (*) (const Standard_ShortReal)) &Abs, "None", py::arg("Value"));

// FUNCTION: HASHCODE
mod.def("HashCode", (Standard_Integer (*) (const Standard_Integer, const Standard_Integer)) &HashCode, "None", py::arg("theMe"), py::arg("theUpper"));

mod.def("HashCode", (Standard_Integer (*) (const long long, const Standard_Integer)) &HashCode, "None", py::arg("theMe"), py::arg("theUpper"));

mod.def("HashCode", (Standard_Integer (*) (const Standard_Utf32Char, const Standard_Integer)) &HashCode, "None", py::arg("theMe"), py::arg("theUpper"));

mod.def("HashCode", (Standard_Integer (*) (const Standard_Address, const Standard_Integer)) &HashCode, "None", py::arg("Value"), py::arg("Upper"));

mod.def("HashCode", (Standard_Integer (*) (const Standard_Size, const Standard_Integer)) &HashCode, "None", py::arg("Val"), py::arg("Upper"));

mod.def("HashCode", (Standard_Integer (*) (const Standard_CString, const Standard_Integer, const Standard_Integer)) &HashCode, "Returns bounded hash code for the first theLen characters in the string theStr, in range [1, theUpper]", py::arg("theStr"), py::arg("theLen"), py::arg("theUpper"));

mod.def("HashCode", (Standard_Integer (*) (const Standard_Transient *, const Standard_Integer)) &HashCode, "Global method HashCode(), for use in hash maps", py::arg("theObject"), py::arg("theUpper"));

mod.def("HashCode", (Standard_Integer (*) (const Standard_ThreadId, const Standard_Integer)) &HashCode, "None", py::arg("Value"), py::arg("Upper"));

// FUNCTION: ISEQUAL
mod.def("IsEqual", (Standard_Boolean (*) (const Standard_Integer, const Standard_Integer)) &IsEqual, "None", py::arg("theOne"), py::arg("theTwo"));

mod.def("IsEqual", (Standard_Boolean (*) (const Standard_Utf32Char, const Standard_Utf32Char)) &IsEqual, "None", py::arg("theOne"), py::arg("theTwo"));

mod.def("IsEqual", (Standard_Boolean (*) (const Standard_Address, const Standard_Address)) &IsEqual, "None", py::arg("One"), py::arg("Two"));

mod.def("IsEqual", (Standard_Boolean (*) (const Standard_Size, const Standard_Size)) &IsEqual, "None", py::arg("One"), py::arg("Two"));

mod.def("IsEqual", (Standard_Boolean (*) (const Standard_Real, const Standard_Real)) &IsEqual, "None", py::arg("Value1"), py::arg("Value2"));

mod.def("IsEqual", (Standard_Boolean (*) (const Standard_Character, const Standard_Character)) &IsEqual, "None", py::arg("One"), py::arg("Two"));

mod.def("IsEqual", (Standard_Boolean (*) (const Standard_ExtCharacter, const Standard_ExtCharacter)) &IsEqual, "None", py::arg("One"), py::arg("Two"));

mod.def("IsEqual", (Standard_Boolean (*) (const Standard_CString, const Standard_CString)) &IsEqual, "Returns Standard_True if two strings are equal", py::arg("theOne"), py::arg("theTwo"));

mod.def("IsEqual", (Standard_Boolean (*) (const Standard_ShortReal, const Standard_ShortReal)) &IsEqual, "None", py::arg("Value1"), py::arg("Value2"));

mod.def("IsEqual", (Standard_Boolean (*) (const Standard_Time, const Standard_Time)) &IsEqual, "None", py::arg("theOne"), py::arg("theTwo"));

// FUNCTION: ISEVEN
mod.def("IsEven", (Standard_Boolean (*) (const Standard_Integer)) &IsEven, "None", py::arg("Value"));

// FUNCTION: ISODD
mod.def("IsOdd", (Standard_Boolean (*) (const Standard_Integer)) &IsOdd, "None", py::arg("Value"));

// FUNCTION: MAX
mod.def("Max", (Standard_Integer (*) (const Standard_Integer, const Standard_Integer)) &Max, "None", py::arg("Val1"), py::arg("Val2"));

mod.def("Max", (Standard_Real (*) (const Standard_Real, const Standard_Real)) &Max, "None", py::arg("Val1"), py::arg("Val2"));

mod.def("Max", (Standard_ShortReal (*) (const Standard_ShortReal, const Standard_ShortReal)) &Max, "None", py::arg("Val1"), py::arg("Val2"));

// FUNCTION: MIN
mod.def("Min", (Standard_Integer (*) (const Standard_Integer, const Standard_Integer)) &Min, "None", py::arg("Val1"), py::arg("Val2"));

mod.def("Min", (Standard_Real (*) (const Standard_Real, const Standard_Real)) &Min, "None", py::arg("Val1"), py::arg("Val2"));

mod.def("Min", (Standard_ShortReal (*) (const Standard_ShortReal, const Standard_ShortReal)) &Min, "None", py::arg("Val1"), py::arg("Val2"));

// FUNCTION: MODULUS
mod.def("Modulus", (Standard_Integer (*) (const Standard_Integer, const Standard_Integer)) &Modulus, "None", py::arg("Value"), py::arg("Divisor"));

// FUNCTION: SQUARE
mod.def("Square", (Standard_Integer (*) (const Standard_Integer)) &Square, "None", py::arg("Value"));

mod.def("Square", (Standard_Real (*) (const Standard_Real)) &Square, "None", py::arg("Value"));

// FUNCTION: INTEGERFIRST
mod.def("IntegerFirst", (Standard_Integer (*) ()) &IntegerFirst, "None");

// FUNCTION: INTEGERLAST
mod.def("IntegerLast", (Standard_Integer (*) ()) &IntegerLast, "None");

// FUNCTION: INTEGERSIZE
mod.def("IntegerSize", (Standard_Integer (*) ()) &IntegerSize, "None");

// FUNCTION: REALSMALL
mod.def("RealSmall", (Standard_Real (*) ()) &RealSmall, "None");

// FUNCTION: REALDIGITS
mod.def("RealDigits", (Standard_Integer (*) ()) &RealDigits, "None");

// FUNCTION: REALEPSILON
mod.def("RealEpsilon", (Standard_Real (*) ()) &RealEpsilon, "None");

// FUNCTION: REALFIRST
mod.def("RealFirst", (Standard_Real (*) ()) &RealFirst, "None");

// FUNCTION: REALFIRST10EXP
mod.def("RealFirst10Exp", (Standard_Integer (*) ()) &RealFirst10Exp, "None");

// FUNCTION: REALLAST
mod.def("RealLast", (Standard_Real (*) ()) &RealLast, "None");

// FUNCTION: REALLAST10EXP
mod.def("RealLast10Exp", (Standard_Integer (*) ()) &RealLast10Exp, "None");

// FUNCTION: REALMANTISSA
mod.def("RealMantissa", (Standard_Integer (*) ()) &RealMantissa, "None");

// FUNCTION: REALRADIX
mod.def("RealRadix", (Standard_Integer (*) ()) &RealRadix, "None");

// FUNCTION: REALSIZE
mod.def("RealSize", (Standard_Integer (*) ()) &RealSize, "None");

// FUNCTION: INTTOREAL
mod.def("IntToReal", (Standard_Real (*) (const Standard_Integer)) &IntToReal, "None", py::arg("Value"));

// FUNCTION: ATAN
mod.def("ATan", (Standard_Real (*) (const Standard_Real)) &ATan, "None", py::arg("Value"));

// FUNCTION: CEILING
mod.def("Ceiling", (Standard_Real (*) (const Standard_Real)) &Ceiling, "None", py::arg("Value"));

// FUNCTION: COS
mod.def("Cos", (Standard_Real (*) (const Standard_Real)) &Cos, "None", py::arg("Value"));

// FUNCTION: EPSILON
mod.def("Epsilon", (Standard_Real (*) (const Standard_Real)) &Epsilon, "None", py::arg("Value"));

// FUNCTION: EXP
mod.def("Exp", (Standard_Real (*) (const Standard_Real)) &Exp, "None", py::arg("Value"));

// FUNCTION: FLOOR
mod.def("Floor", (Standard_Real (*) (const Standard_Real)) &Floor, "None", py::arg("Value"));

// FUNCTION: INTEGERPART
mod.def("IntegerPart", (Standard_Real (*) (const Standard_Real)) &IntegerPart, "None", py::arg("Value"));

// FUNCTION: LOG10
mod.def("Log10", (Standard_Real (*) (const Standard_Real)) &Log10, "None", py::arg("Value"));

// FUNCTION: POW
mod.def("Pow", (Standard_Real (*) (const Standard_Real, const Standard_Real)) &Pow, "None", py::arg("Value"), py::arg("P"));

// FUNCTION: REALPART
mod.def("RealPart", (Standard_Real (*) (const Standard_Real)) &RealPart, "None", py::arg("Value"));

// FUNCTION: REALTOINT
mod.def("RealToInt", (Standard_Integer (*) (const Standard_Real)) &RealToInt, "None", py::arg("Value"));

// FUNCTION: REALTOSHORTREAL
mod.def("RealToShortReal", (Standard_ShortReal (*) (const Standard_Real)) &RealToShortReal, "None", py::arg("theVal"));

// FUNCTION: ROUND
mod.def("Round", (Standard_Real (*) (const Standard_Real)) &Round, "None", py::arg("Value"));

// FUNCTION: SIN
mod.def("Sin", (Standard_Real (*) (const Standard_Real)) &Sin, "None", py::arg("Value"));

// FUNCTION: ASINH
mod.def("ASinh", (Standard_Real (*) (const Standard_Real)) &ASinh, "None", py::arg("Value"));

// FUNCTION: TAN
mod.def("Tan", (Standard_Real (*) (const Standard_Real)) &Tan, "None", py::arg("Value"));

// FUNCTION: TANH
mod.def("Tanh", (Standard_Real (*) (const Standard_Real)) &Tanh, "None", py::arg("Value"));

// FUNCTION: ISALPHABETIC
mod.def("IsAlphabetic", (Standard_Boolean (*) (const Standard_Character)) &IsAlphabetic, "None", py::arg("me"));

// FUNCTION: ISDIGIT
mod.def("IsDigit", (Standard_Boolean (*) (const Standard_Character)) &IsDigit, "None", py::arg("me"));

// FUNCTION: ISXDIGIT
mod.def("IsXDigit", (Standard_Boolean (*) (const Standard_Character)) &IsXDigit, "None", py::arg("me"));

// FUNCTION: ISALPHANUMERIC
mod.def("IsAlphanumeric", (Standard_Boolean (*) (const Standard_Character)) &IsAlphanumeric, "None", py::arg("me"));

// FUNCTION: ISCONTROL
mod.def("IsControl", (Standard_Boolean (*) (const Standard_Character)) &IsControl, "None", py::arg("me"));

// FUNCTION: ISGRAPHIC
mod.def("IsGraphic", (Standard_Boolean (*) (const Standard_Character)) &IsGraphic, "None", py::arg("me"));

// FUNCTION: ISLOWERCASE
mod.def("IsLowerCase", (Standard_Boolean (*) (const Standard_Character)) &IsLowerCase, "None", py::arg("me"));

// FUNCTION: ISPRINTABLE
mod.def("IsPrintable", (Standard_Boolean (*) (const Standard_Character)) &IsPrintable, "None", py::arg("me"));

// FUNCTION: ISPUNCTUATION
mod.def("IsPunctuation", (Standard_Boolean (*) (const Standard_Character)) &IsPunctuation, "None", py::arg("me"));

// FUNCTION: ISSPACE
mod.def("IsSpace", (Standard_Boolean (*) (const Standard_Character)) &IsSpace, "None", py::arg("me"));

// FUNCTION: ISUPPERCASE
mod.def("IsUpperCase", (Standard_Boolean (*) (const Standard_Character)) &IsUpperCase, "None", py::arg("me"));

// FUNCTION: LOWERCASE
mod.def("LowerCase", (Standard_Character (*) (const Standard_Character)) &LowerCase, "None", py::arg("me"));

// FUNCTION: UPPERCASE
mod.def("UpperCase", (Standard_Character (*) (const Standard_Character)) &UpperCase, "None", py::arg("me"));

// FUNCTION: TOEXTCHARACTER
mod.def("ToExtCharacter", (Standard_ExtCharacter (*) (const Standard_Character)) &ToExtCharacter, "None", py::arg("achar"));

// FUNCTION: TOCHARACTER
mod.def("ToCharacter", (Standard_Character (*) (const Standard_ExtCharacter)) &ToCharacter, "None", py::arg("achar"));

// FUNCTION: ISANASCII
mod.def("IsAnAscii", (Standard_Boolean (*) (const Standard_ExtCharacter)) &IsAnAscii, "None", py::arg("achar"));

// FUNCTION: STANDARD_ASSERT_DO_NOTHING
mod.def("Standard_ASSERT_DO_NOTHING", (void (*) ()) &Standard_ASSERT_DO_NOTHING, "This header file defines a set of ASSERT macros intended for use in algorithms for debugging purposes and as a tool to organise checks for abnormal situations in the uniform way.");

// FUNCTION: SHORTREALSMALL
mod.def("ShortRealSmall", (Standard_ShortReal (*) ()) &ShortRealSmall, "None");

// FUNCTION: SHORTREALDIGITS
mod.def("ShortRealDigits", (Standard_Integer (*) ()) &ShortRealDigits, "None");

// FUNCTION: SHORTREALEPSILON
mod.def("ShortRealEpsilon", (Standard_ShortReal (*) ()) &ShortRealEpsilon, "None");

// FUNCTION: SHORTREALFIRST
mod.def("ShortRealFirst", (Standard_ShortReal (*) ()) &ShortRealFirst, "None");

// FUNCTION: SHORTREALFIRST10EXP
mod.def("ShortRealFirst10Exp", (Standard_Integer (*) ()) &ShortRealFirst10Exp, "None");

// FUNCTION: SHORTREALLAST
mod.def("ShortRealLast", (Standard_ShortReal (*) ()) &ShortRealLast, "None");

// FUNCTION: SHORTREALLAST10EXP
mod.def("ShortRealLast10Exp", (Standard_Integer (*) ()) &ShortRealLast10Exp, "None");

// FUNCTION: SHORTREALMANTISSA
mod.def("ShortRealMantissa", (Standard_Integer (*) ()) &ShortRealMantissa, "None");

// FUNCTION: SHORTREALRADIX
mod.def("ShortRealRadix", (Standard_Integer (*) ()) &ShortRealRadix, "None");

// FUNCTION: SHORTREALSIZE
mod.def("ShortRealSize", (Standard_Integer (*) ()) &ShortRealSize, "None");

// FUNCTION: STANDARD_ATOMIC_INCREMENT
mod.def("Standard_Atomic_Increment", (int (*) (volatile int *)) &Standard_Atomic_Increment, "Increments atomically integer variable pointed by theValue and returns resulting incremented value.", py::arg("theValue"));

// FUNCTION: STANDARD_ATOMIC_DECREMENT
mod.def("Standard_Atomic_Decrement", (int (*) (volatile int *)) &Standard_Atomic_Decrement, "Decrements atomically integer variable pointed by theValue and returns resulting decremented value.", py::arg("theValue"));

// TYPEDEF: STANDARD_INTEGER

// TYPEDEF: STANDARD_REAL

// TYPEDEF: STANDARD_BOOLEAN

// TYPEDEF: STANDARD_SHORTREAL

// TYPEDEF: STANDARD_CHARACTER

// TYPEDEF: STANDARD_BYTE
/*
*/

// TYPEDEF: STANDARD_ADDRESS

// TYPEDEF: STANDARD_SIZE

// TYPEDEF: STANDARD_TIME

// TYPEDEF: STANDARD_UTF8CHAR
if (py::hasattr(mod, "Standard_Character")) {
	mod.attr("Standard_Utf8Char") = mod.attr("Standard_Character");
}

// TYPEDEF: STANDARD_UTF8UCHAR
if (py::hasattr(mod, "Standard_Byte")) {
	mod.attr("Standard_Utf8UChar") = mod.attr("Standard_Byte");
}

// TYPEDEF: STANDARD_EXTCHARACTER

// TYPEDEF: STANDARD_UTF16CHAR
if (py::hasattr(mod, "Standard_ExtCharacter")) {
	mod.attr("Standard_Utf16Char") = mod.attr("Standard_ExtCharacter");
}

// TYPEDEF: STANDARD_UTF32CHAR

// TYPEDEF: STANDARD_WIDECHAR

// TYPEDEF: STANDARD_CSTRING

// TYPEDEF: STANDARD_EXTSTRING

// CLASS: STANDARD
py::class_<Standard> cls_Standard(mod, "Standard", "The package Standard provides global memory allocator and other basic services used by other OCCT components.");

// Methods
// cls_Standard.def_static("operator new_", (void * (*)(size_t)) &Standard::operator new, "None", py::arg("theSize"));
// cls_Standard.def_static("operator delete_", (void (*)(void *)) &Standard::operator delete, "None", py::arg("theAddress"));
// cls_Standard.def_static("operator new[]_", (void * (*)(size_t)) &Standard::operator new[], "None", py::arg("theSize"));
// cls_Standard.def_static("operator delete[]_", (void (*)(void *)) &Standard::operator delete[], "None", py::arg("theAddress"));
// cls_Standard.def_static("operator new_", (void * (*)(size_t, void *)) &Standard::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Standard.def_static("operator delete_", (void (*)(void *, void *)) &Standard::operator delete, "None", py::arg(""), py::arg(""));
cls_Standard.def_static("Allocate_", (Standard_Address (*)(const Standard_Size)) &Standard::Allocate, "Allocates memory blocks aSize - bytes to allocate", py::arg("aSize"));
cls_Standard.def_static("Free_", (void (*)(const Standard_Address)) &Standard::Free, "Deallocates memory blocks", py::arg("thePtr"));
cls_Standard.def_static("Reallocate_", (Standard_Address (*)(const Standard_Address, const Standard_Size)) &Standard::Reallocate, "Reallocates memory blocks aStorage - previously allocated memory block aNewSize - new size in bytes", py::arg("aStorage"), py::arg("aNewSize"));
cls_Standard.def_static("AllocateAligned_", (Standard_Address (*)(const Standard_Size, const Standard_Size)) &Standard::AllocateAligned, "Allocates aligned memory blocks. Should be used with CPU instructions which require specific alignment. For example: SSE requires 16 bytes, AVX requires 32 bytes.", py::arg("theSize"), py::arg("theAlign"));
cls_Standard.def_static("FreeAligned_", (void (*)(const Standard_Address)) &Standard::FreeAligned, "Deallocates memory blocks", py::arg("thePtrAligned"));
cls_Standard.def_static("Purge_", (Standard_Integer (*)()) &Standard::Purge, "Deallocates the storage retained on the free list and clears the list. Returns non-zero if some memory has been actually freed.");

// TYPEDEF: STANDARD_OSTREAM
/*
bind_std::basic_ostream<char, std::char_traits<char> >(mod, "Standard_OStream", py::module_local(false));
*/

// CLASS: STANDARD_TRANSIENT
py::class_<Standard_Transient, opencascade::handle<Standard_Transient>> cls_Standard_Transient(mod, "Standard_Transient", "Abstract class which forms the root of the entire Transient class hierarchy.");

// Constructors
cls_Standard_Transient.def(py::init<>());
cls_Standard_Transient.def(py::init<const Standard_Transient &>(), py::arg(""));

// Methods
// cls_Standard_Transient.def_static("operator new_", (void * (*)(size_t)) &Standard_Transient::operator new, "None", py::arg("theSize"));
// cls_Standard_Transient.def_static("operator delete_", (void (*)(void *)) &Standard_Transient::operator delete, "None", py::arg("theAddress"));
// cls_Standard_Transient.def_static("operator new[]_", (void * (*)(size_t)) &Standard_Transient::operator new[], "None", py::arg("theSize"));
// cls_Standard_Transient.def_static("operator delete[]_", (void (*)(void *)) &Standard_Transient::operator delete[], "None", py::arg("theAddress"));
// cls_Standard_Transient.def_static("operator new_", (void * (*)(size_t, void *)) &Standard_Transient::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Standard_Transient.def_static("operator delete_", (void (*)(void *, void *)) &Standard_Transient::operator delete, "None", py::arg(""), py::arg(""));
// cls_Standard_Transient.def("operator=", (Standard_Transient & (Standard_Transient::*)(const Standard_Transient &)) &Standard_Transient::operator=, "Assignment operator, needed to avoid copying reference counter", py::arg(""));
cls_Standard_Transient.def("Delete", (void (Standard_Transient::*)() const) &Standard_Transient::Delete, "Memory deallocator for transient classes");
cls_Standard_Transient.def_static("get_type_name_", (const char * (*)()) &Standard_Transient::get_type_name, "None");
cls_Standard_Transient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_Transient::get_type_descriptor, "Returns type descriptor of Standard_Transient class");
cls_Standard_Transient.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_Transient::*)() const) &Standard_Transient::DynamicType, "Returns a type descriptor about this object.");
cls_Standard_Transient.def("IsInstance", (Standard_Boolean (Standard_Transient::*)(const opencascade::handle<Standard_Type> &) const) &Standard_Transient::IsInstance, "Returns a true value if this is an instance of Type.", py::arg("theType"));
cls_Standard_Transient.def("IsInstance", (Standard_Boolean (Standard_Transient::*)(const Standard_CString) const) &Standard_Transient::IsInstance, "Returns a true value if this is an instance of TypeName.", py::arg("theTypeName"));
cls_Standard_Transient.def("IsKind", (Standard_Boolean (Standard_Transient::*)(const opencascade::handle<Standard_Type> &) const) &Standard_Transient::IsKind, "Returns true if this is an instance of Type or an instance of any class that inherits from Type. Note that multiple inheritance is not supported by OCCT RTTI mechanism.", py::arg("theType"));
cls_Standard_Transient.def("IsKind", (Standard_Boolean (Standard_Transient::*)(const Standard_CString) const) &Standard_Transient::IsKind, "Returns true if this is an instance of TypeName or an instance of any class that inherits from TypeName. Note that multiple inheritance is not supported by OCCT RTTI mechanism.", py::arg("theTypeName"));
cls_Standard_Transient.def("This", (Standard_Transient * (Standard_Transient::*)() const) &Standard_Transient::This, "Returns non-const pointer to this object (like const_cast). For protection against creating handle to objects allocated in stack or call from constructor, it will raise exception Standard_ProgramError if reference counter is zero.");
cls_Standard_Transient.def("GetRefCount", (Standard_Integer (Standard_Transient::*)() const) &Standard_Transient::GetRefCount, "Get the reference counter of this object");
cls_Standard_Transient.def("IncrementRefCounter", (void (Standard_Transient::*)() const) &Standard_Transient::IncrementRefCounter, "Increments the reference counter of this object");
cls_Standard_Transient.def("DecrementRefCounter", (Standard_Integer (Standard_Transient::*)() const) &Standard_Transient::DecrementRefCounter, "Decrements the reference counter of this object; returns the decremented value");

// CLASS: STANDARD_TYPE
py::class_<Standard_Type, opencascade::handle<Standard_Type>, Standard_Transient> cls_Standard_Type(mod, "Standard_Type", "This class provides legacy interface (type descriptor) to run-time type information (RTTI) for OCCT classes inheriting from Standard_Transient.");

// Methods
cls_Standard_Type.def("SystemName", (Standard_CString (Standard_Type::*)() const) &Standard_Type::SystemName, "Returns the system type name of the class (typeinfo.name)");
cls_Standard_Type.def("Name", (Standard_CString (Standard_Type::*)() const) &Standard_Type::Name, "Returns the given name of the class type (get_type_name)");
cls_Standard_Type.def("Size", (Standard_Size (Standard_Type::*)() const) &Standard_Type::Size, "Returns the size of the class instance in bytes");
cls_Standard_Type.def("Parent", (const opencascade::handle<Standard_Type> & (Standard_Type::*)() const) &Standard_Type::Parent, "Returns descriptor of the base class in the hierarchy");
cls_Standard_Type.def("SubType", (Standard_Boolean (Standard_Type::*)(const opencascade::handle<Standard_Type> &) const) &Standard_Type::SubType, "Returns True if this type is the same as theOther, or inherits from theOther. Note that multiple inheritance is not supported.", py::arg("theOther"));
cls_Standard_Type.def("SubType", (Standard_Boolean (Standard_Type::*)(const Standard_CString) const) &Standard_Type::SubType, "Returns True if this type is the same as theOther, or inherits from theOther. Note that multiple inheritance is not supported.", py::arg("theOther"));
cls_Standard_Type.def("Print", (void (Standard_Type::*)(Standard_OStream &) const) &Standard_Type::Print, "Prints type (address of descriptor + name) to a stream", py::arg("theStream"));
cls_Standard_Type.def_static("Register_", (Standard_Type * (*)(const char *, const char *, Standard_Size, const opencascade::handle<Standard_Type> &)) &Standard_Type::Register, "Register a type; returns either new or existing descriptor.", py::arg("theSystemName"), py::arg("theName"), py::arg("theSize"), py::arg("theParent"));
cls_Standard_Type.def_static("get_type_name_", (const char * (*)()) &Standard_Type::get_type_name, "None");
cls_Standard_Type.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_Type::get_type_descriptor, "None");
cls_Standard_Type.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_Type::*)() const) &Standard_Type::DynamicType, "None");

// TYPEDEF: STANDARD_SSTREAM
/*
bind_std::basic_stringstream<char, std::char_traits<char>, std::allocator<char> >(mod, "Standard_SStream", py::module_local(false));
*/

// CLASS: STANDARD_FAILURE
py::class_<Standard_Failure, opencascade::handle<Standard_Failure>, Standard_Transient> cls_Standard_Failure(mod, "Standard_Failure", "Forms the root of the entire exception hierarchy.");

// Constructors
cls_Standard_Failure.def(py::init<>());
cls_Standard_Failure.def(py::init<const Standard_Failure &>(), py::arg("f"));
cls_Standard_Failure.def(py::init<const Standard_CString>(), py::arg("aString"));

// Methods
// cls_Standard_Failure.def("operator=", (Standard_Failure & (Standard_Failure::*)(const Standard_Failure &)) &Standard_Failure::operator=, "Assignment operator", py::arg("f"));
cls_Standard_Failure.def("Print", (void (Standard_Failure::*)(Standard_OStream &) const) &Standard_Failure::Print, "Prints on the stream the exception name followed by the error message. Level: Advanced Warning: The operator 'OStream& operator<< (Standard_OStream&, Handle(Standard_Failure)&)' is implemented. (This operator uses the method Print)", py::arg("s"));
cls_Standard_Failure.def("GetMessageString", (Standard_CString (Standard_Failure::*)() const) &Standard_Failure::GetMessageString, "Returns error message");
cls_Standard_Failure.def("SetMessageString", (void (Standard_Failure::*)(const Standard_CString)) &Standard_Failure::SetMessageString, "Sets error message", py::arg("aMessage"));
cls_Standard_Failure.def("Reraise", (void (Standard_Failure::*)()) &Standard_Failure::Reraise, "None");
cls_Standard_Failure.def("Reraise", (void (Standard_Failure::*)(const Standard_CString)) &Standard_Failure::Reraise, "None", py::arg("aMessage"));
cls_Standard_Failure.def("Reraise", (void (Standard_Failure::*)(const Standard_SStream &)) &Standard_Failure::Reraise, "Reraises a caught exception and changes its error message.", py::arg("aReason"));
cls_Standard_Failure.def_static("Raise_", []() -> void { return Standard_Failure::Raise(); });
cls_Standard_Failure.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_Failure::Raise, "Raises an exception of type 'Failure' and associates an error message to it. The message can be printed in an exception handler.", py::arg("aMessage"));
cls_Standard_Failure.def_static("Raise_", (void (*)(const Standard_SStream &)) &Standard_Failure::Raise, "Raises an exception of type 'Failure' and associates an error message to it. The message can be constructed at run-time.", py::arg("aReason"));
cls_Standard_Failure.def_static("NewInstance_", (opencascade::handle<Standard_Failure> (*)(const Standard_CString)) &Standard_Failure::NewInstance, "Used to construct an instance of the exception object as a handle. Shall be used to protect against possible construction of exception object in C stack -- that is dangerous since some of methods require that object was allocated dynamically.", py::arg("aMessage"));
cls_Standard_Failure.def("Jump", (void (Standard_Failure::*)()) &Standard_Failure::Jump, "Used to throw CASCADE exception from C signal handler. On platforms that do not allow throwing C++ exceptions from this handler (e.g. Linux), uses longjump to get to the current active signal handler, and only then is converted to C++ exception.");
cls_Standard_Failure.def_static("Caught_", (opencascade::handle<Standard_Failure> (*)()) &Standard_Failure::Caught, "Returns the last caught exception. Needed when exceptions are emulated by C longjumps, in other cases is also provided for compatibility.");
cls_Standard_Failure.def_static("get_type_name_", (const char * (*)()) &Standard_Failure::get_type_name, "None");
cls_Standard_Failure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_Failure::get_type_descriptor, "None");
cls_Standard_Failure.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_Failure::*)() const) &Standard_Failure::DynamicType, "None");

// CLASS: STANDARD_DOMAINERROR
py::class_<Standard_DomainError, opencascade::handle<Standard_DomainError>, Standard_Failure> cls_Standard_DomainError(mod, "Standard_DomainError", "None");

// Constructors
cls_Standard_DomainError.def(py::init<>());
cls_Standard_DomainError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_DomainError.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_DomainError::Raise, "None", py::arg("theMessage"));
cls_Standard_DomainError.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_DomainError::Raise, "None", py::arg("theMessage"));
cls_Standard_DomainError.def_static("NewInstance_", (opencascade::handle<Standard_DomainError> (*)(const Standard_CString)) &Standard_DomainError::NewInstance, "None", py::arg("theMessage"));
cls_Standard_DomainError.def_static("get_type_name_", (const char * (*)()) &Standard_DomainError::get_type_name, "None");
cls_Standard_DomainError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_DomainError::get_type_descriptor, "None");
cls_Standard_DomainError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_DomainError::*)() const) &Standard_DomainError::DynamicType, "None");

// CLASS: STANDARD_DIMENSIONERROR
py::class_<Standard_DimensionError, opencascade::handle<Standard_DimensionError>, Standard_DomainError> cls_Standard_DimensionError(mod, "Standard_DimensionError", "None");

// Constructors
cls_Standard_DimensionError.def(py::init<>());
cls_Standard_DimensionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_DimensionError.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_DimensionError::Raise, "None", py::arg("theMessage"));
cls_Standard_DimensionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_DimensionError::Raise, "None", py::arg("theMessage"));
cls_Standard_DimensionError.def_static("NewInstance_", (opencascade::handle<Standard_DimensionError> (*)(const Standard_CString)) &Standard_DimensionError::NewInstance, "None", py::arg("theMessage"));
cls_Standard_DimensionError.def_static("get_type_name_", (const char * (*)()) &Standard_DimensionError::get_type_name, "None");
cls_Standard_DimensionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_DimensionError::get_type_descriptor, "None");
cls_Standard_DimensionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_DimensionError::*)() const) &Standard_DimensionError::DynamicType, "None");

// CLASS: STANDARD_DIMENSIONMISMATCH
py::class_<Standard_DimensionMismatch, opencascade::handle<Standard_DimensionMismatch>, Standard_DimensionError> cls_Standard_DimensionMismatch(mod, "Standard_DimensionMismatch", "None");

// Constructors
cls_Standard_DimensionMismatch.def(py::init<>());
cls_Standard_DimensionMismatch.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_DimensionMismatch.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_DimensionMismatch::Raise, "None", py::arg("theMessage"));
cls_Standard_DimensionMismatch.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_DimensionMismatch::Raise, "None", py::arg("theMessage"));
cls_Standard_DimensionMismatch.def_static("NewInstance_", (opencascade::handle<Standard_DimensionMismatch> (*)(const Standard_CString)) &Standard_DimensionMismatch::NewInstance, "None", py::arg("theMessage"));
cls_Standard_DimensionMismatch.def_static("get_type_name_", (const char * (*)()) &Standard_DimensionMismatch::get_type_name, "None");
cls_Standard_DimensionMismatch.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_DimensionMismatch::get_type_descriptor, "None");
cls_Standard_DimensionMismatch.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_DimensionMismatch::*)() const) &Standard_DimensionMismatch::DynamicType, "None");

// CLASS: STANDARD_PROGRAMERROR
py::class_<Standard_ProgramError, opencascade::handle<Standard_ProgramError>, Standard_Failure> cls_Standard_ProgramError(mod, "Standard_ProgramError", "None");

// Constructors
cls_Standard_ProgramError.def(py::init<>());
cls_Standard_ProgramError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_ProgramError.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_ProgramError::Raise, "None", py::arg("theMessage"));
cls_Standard_ProgramError.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_ProgramError::Raise, "None", py::arg("theMessage"));
cls_Standard_ProgramError.def_static("NewInstance_", (opencascade::handle<Standard_ProgramError> (*)(const Standard_CString)) &Standard_ProgramError::NewInstance, "None", py::arg("theMessage"));
cls_Standard_ProgramError.def_static("get_type_name_", (const char * (*)()) &Standard_ProgramError::get_type_name, "None");
cls_Standard_ProgramError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_ProgramError::get_type_descriptor, "None");
cls_Standard_ProgramError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_ProgramError::*)() const) &Standard_ProgramError::DynamicType, "None");

// CLASS: STANDARD_OUTOFMEMORY
py::class_<Standard_OutOfMemory, opencascade::handle<Standard_OutOfMemory>, Standard_ProgramError> cls_Standard_OutOfMemory(mod, "Standard_OutOfMemory", "Standard_OutOfMemory exception is defined explicitly and not by macro DEFINE_STANDARD_EXCEPTION, to avoid necessity of dynamic memory allocations during throwing and stack unwinding:");

// Constructors
cls_Standard_OutOfMemory.def(py::init<>());
cls_Standard_OutOfMemory.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_OutOfMemory.def("GetMessageString", (Standard_CString (Standard_OutOfMemory::*)() const) &Standard_OutOfMemory::GetMessageString, "Returns error message");
cls_Standard_OutOfMemory.def("SetMessageString", (void (Standard_OutOfMemory::*)(const Standard_CString)) &Standard_OutOfMemory::SetMessageString, "Sets error message", py::arg("aMessage"));
cls_Standard_OutOfMemory.def_static("Raise_", []() -> void { return Standard_OutOfMemory::Raise(); });
cls_Standard_OutOfMemory.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_OutOfMemory::Raise, "Raises exception with specified message string", py::arg("theMessage"));
cls_Standard_OutOfMemory.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_OutOfMemory::Raise, "Raises exception with specified message string", py::arg("theMessage"));
cls_Standard_OutOfMemory.def_static("NewInstance_", []() -> opencascade::handle<Standard_OutOfMemory> { return Standard_OutOfMemory::NewInstance(); });
cls_Standard_OutOfMemory.def_static("NewInstance_", (opencascade::handle<Standard_OutOfMemory> (*)(const Standard_CString)) &Standard_OutOfMemory::NewInstance, "Returns global instance of exception", py::arg("theMessage"));
cls_Standard_OutOfMemory.def_static("get_type_name_", (const char * (*)()) &Standard_OutOfMemory::get_type_name, "None");
cls_Standard_OutOfMemory.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_OutOfMemory::get_type_descriptor, "None");
cls_Standard_OutOfMemory.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_OutOfMemory::*)() const) &Standard_OutOfMemory::DynamicType, "None");

// CLASS: STANDARD_RANGEERROR
py::class_<Standard_RangeError, opencascade::handle<Standard_RangeError>, Standard_DomainError> cls_Standard_RangeError(mod, "Standard_RangeError", "None");

// Constructors
cls_Standard_RangeError.def(py::init<>());
cls_Standard_RangeError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_RangeError.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_RangeError::Raise, "None", py::arg("theMessage"));
cls_Standard_RangeError.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_RangeError::Raise, "None", py::arg("theMessage"));
cls_Standard_RangeError.def_static("NewInstance_", (opencascade::handle<Standard_RangeError> (*)(const Standard_CString)) &Standard_RangeError::NewInstance, "None", py::arg("theMessage"));
cls_Standard_RangeError.def_static("get_type_name_", (const char * (*)()) &Standard_RangeError::get_type_name, "None");
cls_Standard_RangeError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_RangeError::get_type_descriptor, "None");
cls_Standard_RangeError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_RangeError::*)() const) &Standard_RangeError::DynamicType, "None");

// CLASS: STANDARD_OUTOFRANGE
py::class_<Standard_OutOfRange, opencascade::handle<Standard_OutOfRange>, Standard_RangeError> cls_Standard_OutOfRange(mod, "Standard_OutOfRange", "None");

// Constructors
cls_Standard_OutOfRange.def(py::init<>());
cls_Standard_OutOfRange.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_OutOfRange.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_OutOfRange::Raise, "None", py::arg("theMessage"));
cls_Standard_OutOfRange.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_OutOfRange::Raise, "None", py::arg("theMessage"));
cls_Standard_OutOfRange.def_static("NewInstance_", (opencascade::handle<Standard_OutOfRange> (*)(const Standard_CString)) &Standard_OutOfRange::NewInstance, "None", py::arg("theMessage"));
cls_Standard_OutOfRange.def_static("get_type_name_", (const char * (*)()) &Standard_OutOfRange::get_type_name, "None");
cls_Standard_OutOfRange.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_OutOfRange::get_type_descriptor, "None");
cls_Standard_OutOfRange.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_OutOfRange::*)() const) &Standard_OutOfRange::DynamicType, "None");

// CLASS: STANDARD_STATIC_ASSERT
py::class_<Standard_Static_Assert<true>> cls_Standard_Static_Assert(mod, "Standard_Static_Assert", "Static assert -- specialization for condition being true");

// Methods
cls_Standard_Static_Assert.def_static("assert_ok_", (void (*)()) &Standard_Static_Assert<true>::assert_ok, "None");

// CLASS: STANDARD_CONSTRUCTIONERROR
py::class_<Standard_ConstructionError, opencascade::handle<Standard_ConstructionError>, Standard_DomainError> cls_Standard_ConstructionError(mod, "Standard_ConstructionError", "None");

// Constructors
cls_Standard_ConstructionError.def(py::init<>());
cls_Standard_ConstructionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_ConstructionError.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_ConstructionError::Raise, "None", py::arg("theMessage"));
cls_Standard_ConstructionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_ConstructionError::Raise, "None", py::arg("theMessage"));
cls_Standard_ConstructionError.def_static("NewInstance_", (opencascade::handle<Standard_ConstructionError> (*)(const Standard_CString)) &Standard_ConstructionError::NewInstance, "None", py::arg("theMessage"));
cls_Standard_ConstructionError.def_static("get_type_name_", (const char * (*)()) &Standard_ConstructionError::get_type_name, "None");
cls_Standard_ConstructionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_ConstructionError::get_type_descriptor, "None");
cls_Standard_ConstructionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_ConstructionError::*)() const) &Standard_ConstructionError::DynamicType, "None");

// CLASS: STANDARD_NOSUCHOBJECT
py::class_<Standard_NoSuchObject, opencascade::handle<Standard_NoSuchObject>, Standard_DomainError> cls_Standard_NoSuchObject(mod, "Standard_NoSuchObject", "None");

// Constructors
cls_Standard_NoSuchObject.def(py::init<>());
cls_Standard_NoSuchObject.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_NoSuchObject.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_NoSuchObject::Raise, "None", py::arg("theMessage"));
cls_Standard_NoSuchObject.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_NoSuchObject::Raise, "None", py::arg("theMessage"));
cls_Standard_NoSuchObject.def_static("NewInstance_", (opencascade::handle<Standard_NoSuchObject> (*)(const Standard_CString)) &Standard_NoSuchObject::NewInstance, "None", py::arg("theMessage"));
cls_Standard_NoSuchObject.def_static("get_type_name_", (const char * (*)()) &Standard_NoSuchObject::get_type_name, "None");
cls_Standard_NoSuchObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_NoSuchObject::get_type_descriptor, "None");
cls_Standard_NoSuchObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_NoSuchObject::*)() const) &Standard_NoSuchObject::DynamicType, "None");

// TYPEDEF: STANDARD_PCHARACTER

// TYPEDEF: STANDARD_ISTREAM
/*
bind_std::basic_istream<char, std::char_traits<char> >(mod, "Standard_IStream", py::module_local(false));
*/

// TYPEDEF: STANDARD_PEXTCHARACTER

// CLASS: STANDARD_TYPEMISMATCH
py::class_<Standard_TypeMismatch, opencascade::handle<Standard_TypeMismatch>, Standard_DomainError> cls_Standard_TypeMismatch(mod, "Standard_TypeMismatch", "None");

// Constructors
cls_Standard_TypeMismatch.def(py::init<>());
cls_Standard_TypeMismatch.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_TypeMismatch.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_TypeMismatch::Raise, "None", py::arg("theMessage"));
cls_Standard_TypeMismatch.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_TypeMismatch::Raise, "None", py::arg("theMessage"));
cls_Standard_TypeMismatch.def_static("NewInstance_", (opencascade::handle<Standard_TypeMismatch> (*)(const Standard_CString)) &Standard_TypeMismatch::NewInstance, "None", py::arg("theMessage"));
cls_Standard_TypeMismatch.def_static("get_type_name_", (const char * (*)()) &Standard_TypeMismatch::get_type_name, "None");
cls_Standard_TypeMismatch.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_TypeMismatch::get_type_descriptor, "None");
cls_Standard_TypeMismatch.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_TypeMismatch::*)() const) &Standard_TypeMismatch::DynamicType, "None");

// CLASS: STANDARD_PERSISTENT
py::class_<Standard_Persistent, opencascade::handle<Standard_Persistent>, Standard_Transient> cls_Standard_Persistent(mod, "Standard_Persistent", "Root of 'persistent' classes, a legacy support of object oriented databases, now outdated.");

// Constructors
cls_Standard_Persistent.def(py::init<>());

// Methods
// cls_Standard_Persistent.def_static("operator new_", (void * (*)(size_t)) &Standard_Persistent::operator new, "None", py::arg("theSize"));
// cls_Standard_Persistent.def_static("operator delete_", (void (*)(void *)) &Standard_Persistent::operator delete, "None", py::arg("theAddress"));
// cls_Standard_Persistent.def_static("operator new[]_", (void * (*)(size_t)) &Standard_Persistent::operator new[], "None", py::arg("theSize"));
// cls_Standard_Persistent.def_static("operator delete[]_", (void (*)(void *)) &Standard_Persistent::operator delete[], "None", py::arg("theAddress"));
// cls_Standard_Persistent.def_static("operator new_", (void * (*)(size_t, void *)) &Standard_Persistent::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Standard_Persistent.def_static("operator delete_", (void (*)(void *, void *)) &Standard_Persistent::operator delete, "None", py::arg(""), py::arg(""));
cls_Standard_Persistent.def_static("get_type_name_", (const char * (*)()) &Standard_Persistent::get_type_name, "None");
cls_Standard_Persistent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_Persistent::get_type_descriptor, "None");
cls_Standard_Persistent.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_Persistent::*)() const) &Standard_Persistent::DynamicType, "None");
cls_Standard_Persistent.def("TypeNum", (Standard_Integer & (Standard_Persistent::*)()) &Standard_Persistent::TypeNum, "None");

// TYPEDEF: STANDARD_UUID
py::class_<_GUID> cls__Standard_UUID(mod, "Standard_UUID", "None");

// Fields
cls__Standard_UUID.def_readwrite("Data1", &_GUID::Data1, "None");
cls__Standard_UUID.def_readwrite("Data2", &_GUID::Data2, "None");
cls__Standard_UUID.def_readwrite("Data3", &_GUID::Data3, "None");
// cls__Standard_UUID.def_readwrite("Data4", &_GUID::Data4, "None");

// CLASS: STANDARD_GUID
py::class_<Standard_GUID> cls_Standard_GUID(mod, "Standard_GUID", "None");

// Constructors
cls_Standard_GUID.def(py::init<>());
cls_Standard_GUID.def(py::init<const Standard_CString>(), py::arg("aGuid"));
cls_Standard_GUID.def(py::init<const Standard_ExtString>(), py::arg("aGuid"));
cls_Standard_GUID.def(py::init<const Standard_Integer, const Standard_ExtCharacter, const Standard_ExtCharacter, const Standard_ExtCharacter, const Standard_Byte, const Standard_Byte, const Standard_Byte, const Standard_Byte, const Standard_Byte, const Standard_Byte>(), py::arg("a32b"), py::arg("a16b1"), py::arg("a16b2"), py::arg("a16b3"), py::arg("a8b1"), py::arg("a8b2"), py::arg("a8b3"), py::arg("a8b4"), py::arg("a8b5"), py::arg("a8b6"));
cls_Standard_GUID.def(py::init<const Standard_UUID &>(), py::arg("aGuid"));
cls_Standard_GUID.def(py::init<const Standard_GUID &>(), py::arg("aGuid"));

// Methods
// cls_Standard_GUID.def_static("operator new_", (void * (*)(size_t)) &Standard_GUID::operator new, "None", py::arg("theSize"));
// cls_Standard_GUID.def_static("operator delete_", (void (*)(void *)) &Standard_GUID::operator delete, "None", py::arg("theAddress"));
// cls_Standard_GUID.def_static("operator new[]_", (void * (*)(size_t)) &Standard_GUID::operator new[], "None", py::arg("theSize"));
// cls_Standard_GUID.def_static("operator delete[]_", (void (*)(void *)) &Standard_GUID::operator delete[], "None", py::arg("theAddress"));
// cls_Standard_GUID.def_static("operator new_", (void * (*)(size_t, void *)) &Standard_GUID::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Standard_GUID.def_static("operator delete_", (void (*)(void *, void *)) &Standard_GUID::operator delete, "None", py::arg(""), py::arg(""));
cls_Standard_GUID.def("ToUUID", (Standard_UUID (Standard_GUID::*)() const) &Standard_GUID::ToUUID, "None");
cls_Standard_GUID.def("ToCString", (void (Standard_GUID::*)(const Standard_PCharacter) const) &Standard_GUID::ToCString, "translate the GUID into ascii string the aStrGuid is allocated by user. the guid have the following format:", py::arg("aStrGuid"));
cls_Standard_GUID.def("ToExtString", (void (Standard_GUID::*)(const Standard_PExtCharacter) const) &Standard_GUID::ToExtString, "translate the GUID into unicode string the aStrGuid is allocated by user. the guid have the following format:", py::arg("aStrGuid"));
cls_Standard_GUID.def("IsSame", (Standard_Boolean (Standard_GUID::*)(const Standard_GUID &) const) &Standard_GUID::IsSame, "None", py::arg("uid"));
cls_Standard_GUID.def("__eq__", (Standard_Boolean (Standard_GUID::*)(const Standard_GUID &) const) &Standard_GUID::operator==, py::is_operator(), "None", py::arg("uid"));
cls_Standard_GUID.def("IsNotSame", (Standard_Boolean (Standard_GUID::*)(const Standard_GUID &) const) &Standard_GUID::IsNotSame, "None", py::arg("uid"));
cls_Standard_GUID.def("__ne__", (Standard_Boolean (Standard_GUID::*)(const Standard_GUID &) const) &Standard_GUID::operator!=, py::is_operator(), "None", py::arg("uid"));
cls_Standard_GUID.def("Assign", (void (Standard_GUID::*)(const Standard_GUID &)) &Standard_GUID::Assign, "None", py::arg("uid"));
// cls_Standard_GUID.def("operator=", (void (Standard_GUID::*)(const Standard_GUID &)) &Standard_GUID::operator=, "None", py::arg("uid"));
cls_Standard_GUID.def("Assign", (void (Standard_GUID::*)(const Standard_UUID &)) &Standard_GUID::Assign, "None", py::arg("uid"));
// cls_Standard_GUID.def("operator=", (void (Standard_GUID::*)(const Standard_UUID &)) &Standard_GUID::operator=, "None", py::arg("uid"));
cls_Standard_GUID.def("ShallowDump", (void (Standard_GUID::*)(Standard_OStream &) const) &Standard_GUID::ShallowDump, "Display the GUID with the following format:", py::arg("aStream"));
cls_Standard_GUID.def_static("CheckGUIDFormat_", (Standard_Boolean (*)(const Standard_CString)) &Standard_GUID::CheckGUIDFormat, "Check the format of a GUID string. It checks the size, the position of the '-' and the correct size of fields.", py::arg("aGuid"));
cls_Standard_GUID.def("Hash", (Standard_Integer (Standard_GUID::*)(const Standard_Integer) const) &Standard_GUID::Hash, "Hash function for GUID.", py::arg("Upper"));
cls_Standard_GUID.def_static("HashCode_", (Standard_Integer (*)(const Standard_GUID &, const Standard_Integer)) &Standard_GUID::HashCode, "H method used by collections.", py::arg("aguid"), py::arg("Upper"));
cls_Standard_GUID.def_static("IsEqual_", (Standard_Boolean (*)(const Standard_GUID &, const Standard_GUID &)) &Standard_GUID::IsEqual, "Returns True when the two GUID are the same.", py::arg("string1"), py::arg("string2"));

// CLASS: STANDARD_MULTIPLYDEFINED
py::class_<Standard_MultiplyDefined, opencascade::handle<Standard_MultiplyDefined>, Standard_DomainError> cls_Standard_MultiplyDefined(mod, "Standard_MultiplyDefined", "None");

// Constructors
cls_Standard_MultiplyDefined.def(py::init<>());
cls_Standard_MultiplyDefined.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_MultiplyDefined.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_MultiplyDefined::Raise, "None", py::arg("theMessage"));
cls_Standard_MultiplyDefined.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_MultiplyDefined::Raise, "None", py::arg("theMessage"));
cls_Standard_MultiplyDefined.def_static("NewInstance_", (opencascade::handle<Standard_MultiplyDefined> (*)(const Standard_CString)) &Standard_MultiplyDefined::NewInstance, "None", py::arg("theMessage"));
cls_Standard_MultiplyDefined.def_static("get_type_name_", (const char * (*)()) &Standard_MultiplyDefined::get_type_name, "None");
cls_Standard_MultiplyDefined.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_MultiplyDefined::get_type_descriptor, "None");
cls_Standard_MultiplyDefined.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_MultiplyDefined::*)() const) &Standard_MultiplyDefined::DynamicType, "None");

// CLASS: STANDARD_IMMUTABLEOBJECT
py::class_<Standard_ImmutableObject, opencascade::handle<Standard_ImmutableObject>, Standard_DomainError> cls_Standard_ImmutableObject(mod, "Standard_ImmutableObject", "None");

// Constructors
cls_Standard_ImmutableObject.def(py::init<>());
cls_Standard_ImmutableObject.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_ImmutableObject.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_ImmutableObject::Raise, "None", py::arg("theMessage"));
cls_Standard_ImmutableObject.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_ImmutableObject::Raise, "None", py::arg("theMessage"));
cls_Standard_ImmutableObject.def_static("NewInstance_", (opencascade::handle<Standard_ImmutableObject> (*)(const Standard_CString)) &Standard_ImmutableObject::NewInstance, "None", py::arg("theMessage"));
cls_Standard_ImmutableObject.def_static("get_type_name_", (const char * (*)()) &Standard_ImmutableObject::get_type_name, "None");
cls_Standard_ImmutableObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_ImmutableObject::get_type_descriptor, "None");
cls_Standard_ImmutableObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_ImmutableObject::*)() const) &Standard_ImmutableObject::DynamicType, "None");

// TYPEDEF: STANDARD_PERRORHANDLER

// TYPEDEF: STANDARD_JMPBUF

// TYPEDEF: STANDARD_THREADID

// CLASS: STANDARD_ERRORHANDLER
py::class_<Standard_ErrorHandler> cls_Standard_ErrorHandler(mod, "Standard_ErrorHandler", "Class implementing mechanics of conversion of signals to exceptions.");

// Constructors
cls_Standard_ErrorHandler.def(py::init<>());

// Methods
// cls_Standard_ErrorHandler.def_static("operator new_", (void * (*)(size_t)) &Standard_ErrorHandler::operator new, "None", py::arg("theSize"));
// cls_Standard_ErrorHandler.def_static("operator delete_", (void (*)(void *)) &Standard_ErrorHandler::operator delete, "None", py::arg("theAddress"));
// cls_Standard_ErrorHandler.def_static("operator new[]_", (void * (*)(size_t)) &Standard_ErrorHandler::operator new[], "None", py::arg("theSize"));
// cls_Standard_ErrorHandler.def_static("operator delete[]_", (void (*)(void *)) &Standard_ErrorHandler::operator delete[], "None", py::arg("theAddress"));
// cls_Standard_ErrorHandler.def_static("operator new_", (void * (*)(size_t, void *)) &Standard_ErrorHandler::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Standard_ErrorHandler.def_static("operator delete_", (void (*)(void *, void *)) &Standard_ErrorHandler::operator delete, "None", py::arg(""), py::arg(""));
cls_Standard_ErrorHandler.def("Destroy", (void (Standard_ErrorHandler::*)()) &Standard_ErrorHandler::Destroy, "Unlinks and checks if there is a raised exception.");
cls_Standard_ErrorHandler.def("Unlink", (void (Standard_ErrorHandler::*)()) &Standard_ErrorHandler::Unlink, "Removes handler from the handlers list");
cls_Standard_ErrorHandler.def("Catches", (Standard_Boolean (Standard_ErrorHandler::*)(const opencascade::handle<Standard_Type> &)) &Standard_ErrorHandler::Catches, "Returns 'True' if the caught exception has the same type or inherits from 'aType'", py::arg("aType"));
cls_Standard_ErrorHandler.def("Label", (Standard_JmpBuf & (Standard_ErrorHandler::*)()) &Standard_ErrorHandler::Label, "Returns label for jump");
cls_Standard_ErrorHandler.def("Error", (opencascade::handle<Standard_Failure> (Standard_ErrorHandler::*)() const) &Standard_ErrorHandler::Error, "Returns the current Error.");
cls_Standard_ErrorHandler.def_static("LastCaughtError_", (opencascade::handle<Standard_Failure> (*)()) &Standard_ErrorHandler::LastCaughtError, "Returns the caught exception.");
cls_Standard_ErrorHandler.def_static("IsInTryBlock_", (Standard_Boolean (*)()) &Standard_ErrorHandler::IsInTryBlock, "Test if the code is currently running in a try block");

// TYPEDEF: STANDARD_ERRORHANDLERCALLBACK
py::class_<Standard_ErrorHandler::Callback> cls_Standard_ErrorHandler_Standard_ErrorHandlerCallback(mod, "Standard_ErrorHandlerCallback", "Defines a base class for callback objects that can be registered in the OCC error handler (the class simulating C++ exceptions) so as to be correctly destroyed when error handler is activated.");

// Methods
// cls_Standard_ErrorHandler_Standard_ErrorHandlerCallback.def_static("operator new_", (void * (*)(size_t)) &Standard_ErrorHandler::Callback::operator new, "None", py::arg("theSize"));
// cls_Standard_ErrorHandler_Standard_ErrorHandlerCallback.def_static("operator delete_", (void (*)(void *)) &Standard_ErrorHandler::Callback::operator delete, "None", py::arg("theAddress"));
// cls_Standard_ErrorHandler_Standard_ErrorHandlerCallback.def_static("operator new[]_", (void * (*)(size_t)) &Standard_ErrorHandler::Callback::operator new[], "None", py::arg("theSize"));
// cls_Standard_ErrorHandler_Standard_ErrorHandlerCallback.def_static("operator delete[]_", (void (*)(void *)) &Standard_ErrorHandler::Callback::operator delete[], "None", py::arg("theAddress"));
// cls_Standard_ErrorHandler_Standard_ErrorHandlerCallback.def_static("operator new_", (void * (*)(size_t, void *)) &Standard_ErrorHandler::Callback::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Standard_ErrorHandler_Standard_ErrorHandlerCallback.def_static("operator delete_", (void (*)(void *, void *)) &Standard_ErrorHandler::Callback::operator delete, "None", py::arg(""), py::arg(""));
cls_Standard_ErrorHandler_Standard_ErrorHandlerCallback.def("RegisterCallback", (void (Standard_ErrorHandler::Callback::*)()) &Standard_ErrorHandler::Callback::RegisterCallback, "Registers this callback object in the current error handler (if found).");
cls_Standard_ErrorHandler_Standard_ErrorHandlerCallback.def("UnregisterCallback", (void (Standard_ErrorHandler::Callback::*)()) &Standard_ErrorHandler::Callback::UnregisterCallback, "Unregisters this callback object from the error handler.");
cls_Standard_ErrorHandler_Standard_ErrorHandlerCallback.def("DestroyCallback", (void (Standard_ErrorHandler::Callback::*)()) &Standard_ErrorHandler::Callback::DestroyCallback, "The callback function to perform necessary callback action. Called by the exception handler when it is being destroyed but still has this callback registered.");

// CLASS: STANDARD_MUTEX
py::class_<Standard_Mutex, Standard_ErrorHandler::Callback> cls_Standard_Mutex(mod, "Standard_Mutex", "Mutex: a class to synchronize access to shared data.");

// Constructors
cls_Standard_Mutex.def(py::init<>());

// Methods
cls_Standard_Mutex.def("Lock", (void (Standard_Mutex::*)()) &Standard_Mutex::Lock, "Method to lock the mutex; waits until the mutex is released by other threads, locks it and then returns");
cls_Standard_Mutex.def("TryLock", (Standard_Boolean (Standard_Mutex::*)()) &Standard_Mutex::TryLock, "Method to test the mutex; if the mutex is not hold by other thread, locks it and returns True; otherwise returns False without waiting mutex to be released.");
cls_Standard_Mutex.def("Unlock", (void (Standard_Mutex::*)()) &Standard_Mutex::Unlock, "Method to unlock the mutex; releases it to other users");

// CLASS: STANDARD_NULLOBJECT
py::class_<Standard_NullObject, opencascade::handle<Standard_NullObject>, Standard_DomainError> cls_Standard_NullObject(mod, "Standard_NullObject", "None");

// Constructors
cls_Standard_NullObject.def(py::init<>());
cls_Standard_NullObject.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_NullObject.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_NullObject::Raise, "None", py::arg("theMessage"));
cls_Standard_NullObject.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_NullObject::Raise, "None", py::arg("theMessage"));
cls_Standard_NullObject.def_static("NewInstance_", (opencascade::handle<Standard_NullObject> (*)(const Standard_CString)) &Standard_NullObject::NewInstance, "None", py::arg("theMessage"));
cls_Standard_NullObject.def_static("get_type_name_", (const char * (*)()) &Standard_NullObject::get_type_name, "None");
cls_Standard_NullObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_NullObject::get_type_descriptor, "None");
cls_Standard_NullObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_NullObject::*)() const) &Standard_NullObject::DynamicType, "None");

// CLASS: STANDARD_NOTIMPLEMENTED
py::class_<Standard_NotImplemented, opencascade::handle<Standard_NotImplemented>, Standard_ProgramError> cls_Standard_NotImplemented(mod, "Standard_NotImplemented", "None");

// Constructors
cls_Standard_NotImplemented.def(py::init<>());
cls_Standard_NotImplemented.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_NotImplemented.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_NotImplemented::Raise, "None", py::arg("theMessage"));
cls_Standard_NotImplemented.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_NotImplemented::Raise, "None", py::arg("theMessage"));
cls_Standard_NotImplemented.def_static("NewInstance_", (opencascade::handle<Standard_NotImplemented> (*)(const Standard_CString)) &Standard_NotImplemented::NewInstance, "None", py::arg("theMessage"));
cls_Standard_NotImplemented.def_static("get_type_name_", (const char * (*)()) &Standard_NotImplemented::get_type_name, "None");
cls_Standard_NotImplemented.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_NotImplemented::get_type_descriptor, "None");
cls_Standard_NotImplemented.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_NotImplemented::*)() const) &Standard_NotImplemented::DynamicType, "None");

// CLASS: STANDARD_NEGATIVEVALUE
py::class_<Standard_NegativeValue, opencascade::handle<Standard_NegativeValue>, Standard_RangeError> cls_Standard_NegativeValue(mod, "Standard_NegativeValue", "None");

// Constructors
cls_Standard_NegativeValue.def(py::init<>());
cls_Standard_NegativeValue.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_NegativeValue.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_NegativeValue::Raise, "None", py::arg("theMessage"));
cls_Standard_NegativeValue.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_NegativeValue::Raise, "None", py::arg("theMessage"));
cls_Standard_NegativeValue.def_static("NewInstance_", (opencascade::handle<Standard_NegativeValue> (*)(const Standard_CString)) &Standard_NegativeValue::NewInstance, "None", py::arg("theMessage"));
cls_Standard_NegativeValue.def_static("get_type_name_", (const char * (*)()) &Standard_NegativeValue::get_type_name, "None");
cls_Standard_NegativeValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_NegativeValue::get_type_descriptor, "None");
cls_Standard_NegativeValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_NegativeValue::*)() const) &Standard_NegativeValue::DynamicType, "None");

// CLASS: STANDARD_NULLVALUE
py::class_<Standard_NullValue, opencascade::handle<Standard_NullValue>, Standard_RangeError> cls_Standard_NullValue(mod, "Standard_NullValue", "None");

// Constructors
cls_Standard_NullValue.def(py::init<>());
cls_Standard_NullValue.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_NullValue.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_NullValue::Raise, "None", py::arg("theMessage"));
cls_Standard_NullValue.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_NullValue::Raise, "None", py::arg("theMessage"));
cls_Standard_NullValue.def_static("NewInstance_", (opencascade::handle<Standard_NullValue> (*)(const Standard_CString)) &Standard_NullValue::NewInstance, "None", py::arg("theMessage"));
cls_Standard_NullValue.def_static("get_type_name_", (const char * (*)()) &Standard_NullValue::get_type_name, "None");
cls_Standard_NullValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_NullValue::get_type_descriptor, "None");
cls_Standard_NullValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_NullValue::*)() const) &Standard_NullValue::DynamicType, "None");

// CLASS: STANDARD_ABORTIVETRANSACTION
py::class_<Standard_AbortiveTransaction, opencascade::handle<Standard_AbortiveTransaction>, Standard_Failure> cls_Standard_AbortiveTransaction(mod, "Standard_AbortiveTransaction", "None");

// Constructors
cls_Standard_AbortiveTransaction.def(py::init<>());
cls_Standard_AbortiveTransaction.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_AbortiveTransaction.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_AbortiveTransaction::Raise, "None", py::arg("theMessage"));
cls_Standard_AbortiveTransaction.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_AbortiveTransaction::Raise, "None", py::arg("theMessage"));
cls_Standard_AbortiveTransaction.def_static("NewInstance_", (opencascade::handle<Standard_AbortiveTransaction> (*)(const Standard_CString)) &Standard_AbortiveTransaction::NewInstance, "None", py::arg("theMessage"));
cls_Standard_AbortiveTransaction.def_static("get_type_name_", (const char * (*)()) &Standard_AbortiveTransaction::get_type_name, "None");
cls_Standard_AbortiveTransaction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_AbortiveTransaction::get_type_descriptor, "None");
cls_Standard_AbortiveTransaction.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_AbortiveTransaction::*)() const) &Standard_AbortiveTransaction::DynamicType, "None");

// CLASS: STANDARD_ARRAYSTREAMBUFFER
py::class_<Standard_ArrayStreamBuffer> cls_Standard_ArrayStreamBuffer(mod, "Standard_ArrayStreamBuffer", "Custom buffer object implementing STL interface std::streambuf for streamed reading from allocated memory block. Implements minimal sub-set of methods for passing buffer to std::istream, including seek support.");

// Constructors
cls_Standard_ArrayStreamBuffer.def(py::init<const char *, const size_t>(), py::arg("theBegin"), py::arg("theSize"));

// Methods
cls_Standard_ArrayStreamBuffer.def("Init", (void (Standard_ArrayStreamBuffer::*)(const char *, const size_t)) &Standard_ArrayStreamBuffer::Init, "(Re)-initialize the stream. Passed pointer is stored as is (memory is NOT copied nor released with destructor).", py::arg("theBegin"), py::arg("theSize"));
cls_Standard_ArrayStreamBuffer.def("xsgetn", (std::streamsize (Standard_ArrayStreamBuffer::*)(char *, std::streamsize)) &Standard_ArrayStreamBuffer::xsgetn, "Read a bunch of bytes at once.", py::arg("thePtr"), py::arg("theCount"));

// CLASS: STANDARD_CLOCALESENTRY
py::class_<Standard_CLocaleSentry> cls_Standard_CLocaleSentry(mod, "Standard_CLocaleSentry", "This class intended to temporary switch C locale and logically equivalent to setlocale(LC_ALL, 'C'). It is intended to format text regardless of user locale settings (for import/export functionality). Thus following calls to sprintf, atoi and other functions will use 'C' locale. Destructor of this class will return original locale.");

// Constructors
cls_Standard_CLocaleSentry.def(py::init<>());

// Methods
cls_Standard_CLocaleSentry.def_static("GetCLocale_", (Standard_CLocaleSentry::clocale_t (*)()) &Standard_CLocaleSentry::GetCLocale, "Returns locale 'C' instance (locale_t within xlocale or _locale_t within Windows) to be used for _l functions with locale argument.");

// CLASS: STANDARD_NUMERICERROR
py::class_<Standard_NumericError, opencascade::handle<Standard_NumericError>, Standard_Failure> cls_Standard_NumericError(mod, "Standard_NumericError", "None");

// Constructors
cls_Standard_NumericError.def(py::init<>());
cls_Standard_NumericError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_NumericError.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_NumericError::Raise, "None", py::arg("theMessage"));
cls_Standard_NumericError.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_NumericError::Raise, "None", py::arg("theMessage"));
cls_Standard_NumericError.def_static("NewInstance_", (opencascade::handle<Standard_NumericError> (*)(const Standard_CString)) &Standard_NumericError::NewInstance, "None", py::arg("theMessage"));
cls_Standard_NumericError.def_static("get_type_name_", (const char * (*)()) &Standard_NumericError::get_type_name, "None");
cls_Standard_NumericError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_NumericError::get_type_descriptor, "None");
cls_Standard_NumericError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_NumericError::*)() const) &Standard_NumericError::DynamicType, "None");

// CLASS: STANDARD_DIVIDEBYZERO
py::class_<Standard_DivideByZero, opencascade::handle<Standard_DivideByZero>, Standard_NumericError> cls_Standard_DivideByZero(mod, "Standard_DivideByZero", "None");

// Constructors
cls_Standard_DivideByZero.def(py::init<>());
cls_Standard_DivideByZero.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_DivideByZero.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_DivideByZero::Raise, "None", py::arg("theMessage"));
cls_Standard_DivideByZero.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_DivideByZero::Raise, "None", py::arg("theMessage"));
cls_Standard_DivideByZero.def_static("NewInstance_", (opencascade::handle<Standard_DivideByZero> (*)(const Standard_CString)) &Standard_DivideByZero::NewInstance, "None", py::arg("theMessage"));
cls_Standard_DivideByZero.def_static("get_type_name_", (const char * (*)()) &Standard_DivideByZero::get_type_name, "None");
cls_Standard_DivideByZero.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_DivideByZero::get_type_descriptor, "None");
cls_Standard_DivideByZero.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_DivideByZero::*)() const) &Standard_DivideByZero::DynamicType, "None");

// CLASS: STANDARD_LICENSEERROR
py::class_<Standard_LicenseError, opencascade::handle<Standard_LicenseError>, Standard_Failure> cls_Standard_LicenseError(mod, "Standard_LicenseError", "None");

// Constructors
cls_Standard_LicenseError.def(py::init<>());
cls_Standard_LicenseError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_LicenseError.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_LicenseError::Raise, "None", py::arg("theMessage"));
cls_Standard_LicenseError.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_LicenseError::Raise, "None", py::arg("theMessage"));
cls_Standard_LicenseError.def_static("NewInstance_", (opencascade::handle<Standard_LicenseError> (*)(const Standard_CString)) &Standard_LicenseError::NewInstance, "None", py::arg("theMessage"));
cls_Standard_LicenseError.def_static("get_type_name_", (const char * (*)()) &Standard_LicenseError::get_type_name, "None");
cls_Standard_LicenseError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_LicenseError::get_type_descriptor, "None");
cls_Standard_LicenseError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_LicenseError::*)() const) &Standard_LicenseError::DynamicType, "None");

// CLASS: STANDARD_LICENSENOTFOUND
py::class_<Standard_LicenseNotFound, opencascade::handle<Standard_LicenseNotFound>, Standard_LicenseError> cls_Standard_LicenseNotFound(mod, "Standard_LicenseNotFound", "None");

// Constructors
cls_Standard_LicenseNotFound.def(py::init<>());
cls_Standard_LicenseNotFound.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_LicenseNotFound.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_LicenseNotFound::Raise, "None", py::arg("theMessage"));
cls_Standard_LicenseNotFound.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_LicenseNotFound::Raise, "None", py::arg("theMessage"));
cls_Standard_LicenseNotFound.def_static("NewInstance_", (opencascade::handle<Standard_LicenseNotFound> (*)(const Standard_CString)) &Standard_LicenseNotFound::NewInstance, "None", py::arg("theMessage"));
cls_Standard_LicenseNotFound.def_static("get_type_name_", (const char * (*)()) &Standard_LicenseNotFound::get_type_name, "None");
cls_Standard_LicenseNotFound.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_LicenseNotFound::get_type_descriptor, "None");
cls_Standard_LicenseNotFound.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_LicenseNotFound::*)() const) &Standard_LicenseNotFound::DynamicType, "None");

// CLASS: STANDARD_MMGRROOT
py::class_<Standard_MMgrRoot> cls_Standard_MMgrRoot(mod, "Standard_MMgrRoot", "Root class for Open CASCADE mmemory managers. Defines only abstract interface functions.");

// Methods
cls_Standard_MMgrRoot.def("Allocate", (Standard_Address (Standard_MMgrRoot::*)(const Standard_Size)) &Standard_MMgrRoot::Allocate, "Allocate specified number of bytes. The actually allocated space should be rounded up to double word size (4 bytes), as this is expected by implementation of some classes in OCC (e.g. TCollection_AsciiString)", py::arg("theSize"));
cls_Standard_MMgrRoot.def("Reallocate", (Standard_Address (Standard_MMgrRoot::*)(Standard_Address, const Standard_Size)) &Standard_MMgrRoot::Reallocate, "Reallocate previously allocated memory to contain at least theSize bytes. In case of success, new pointer is returned.", py::arg("thePtr"), py::arg("theSize"));
cls_Standard_MMgrRoot.def("Free", (void (Standard_MMgrRoot::*)(Standard_Address)) &Standard_MMgrRoot::Free, "Frees previously allocated memory at specified address.", py::arg("thePtr"));
cls_Standard_MMgrRoot.def("Purge", [](Standard_MMgrRoot &self) -> Standard_Integer { return self.Purge(); });
cls_Standard_MMgrRoot.def("Purge", (Standard_Integer (Standard_MMgrRoot::*)(Standard_Boolean)) &Standard_MMgrRoot::Purge, "Purge internally cached unused memory blocks (if any) by releasing them to the operating system. Must return non-zero if some memory has been actually released, or zero otherwise.", py::arg("isDestroyed"));

// CLASS: STANDARD_MMGROPT
py::class_<Standard_MMgrOpt, Standard_MMgrRoot> cls_Standard_MMgrOpt(mod, "Standard_MMgrOpt", "Open CASCADE memory manager optimized for speed.");

// Constructors
cls_Standard_MMgrOpt.def(py::init<>());
cls_Standard_MMgrOpt.def(py::init<const Standard_Boolean>(), py::arg("aClear"));
cls_Standard_MMgrOpt.def(py::init<const Standard_Boolean, const Standard_Boolean>(), py::arg("aClear"), py::arg("aMMap"));
cls_Standard_MMgrOpt.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Size>(), py::arg("aClear"), py::arg("aMMap"), py::arg("aCellSize"));
cls_Standard_MMgrOpt.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Size, const Standard_Integer>(), py::arg("aClear"), py::arg("aMMap"), py::arg("aCellSize"), py::arg("aNbPages"));
cls_Standard_MMgrOpt.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Size, const Standard_Integer, const Standard_Size>(), py::arg("aClear"), py::arg("aMMap"), py::arg("aCellSize"), py::arg("aNbPages"), py::arg("aThreshold"));

// Methods
cls_Standard_MMgrOpt.def("Allocate", (Standard_Address (Standard_MMgrOpt::*)(const Standard_Size)) &Standard_MMgrOpt::Allocate, "Allocate aSize bytes; see class description above", py::arg("aSize"));
cls_Standard_MMgrOpt.def("Reallocate", (Standard_Address (Standard_MMgrOpt::*)(Standard_Address, const Standard_Size)) &Standard_MMgrOpt::Reallocate, "Reallocate previously allocated aPtr to a new size; new address is returned. In case that aPtr is null, the function behaves exactly as Allocate.", py::arg("thePtr"), py::arg("theSize"));
cls_Standard_MMgrOpt.def("Free", (void (Standard_MMgrOpt::*)(Standard_Address)) &Standard_MMgrOpt::Free, "Free previously allocated block. Note that block can not all blocks are released to the OS by this method (see class description)", py::arg("thePtr"));
cls_Standard_MMgrOpt.def("Purge", (Standard_Integer (Standard_MMgrOpt::*)(Standard_Boolean)) &Standard_MMgrOpt::Purge, "Release medium-sized blocks of memory in free lists to the system. Returns number of actually freed blocks", py::arg("isDestroyed"));
cls_Standard_MMgrOpt.def_static("SetCallBackFunction_", (void (*)(Standard_MMgrOpt::TPCallBackFunc)) &Standard_MMgrOpt::SetCallBackFunction, "Set the callback function. You may pass 0 there to turn off the callback. The callback function, if set, will be automatically called from within Allocate and Free methods.", py::arg("pFunc"));

// CLASS: STANDARD_MMGRRAW
py::class_<Standard_MMgrRaw, Standard_MMgrRoot> cls_Standard_MMgrRaw(mod, "Standard_MMgrRaw", "Implementation of raw OCC memory manager which uses standard C functions: malloc (or calloc), free and realloc without any optimization");

// Constructors
cls_Standard_MMgrRaw.def(py::init<>());
cls_Standard_MMgrRaw.def(py::init<const Standard_Boolean>(), py::arg("aClear"));

// Methods
cls_Standard_MMgrRaw.def("Allocate", (Standard_Address (Standard_MMgrRaw::*)(const Standard_Size)) &Standard_MMgrRaw::Allocate, "Allocate aSize bytes", py::arg("aSize"));
cls_Standard_MMgrRaw.def("Reallocate", (Standard_Address (Standard_MMgrRaw::*)(Standard_Address, const Standard_Size)) &Standard_MMgrRaw::Reallocate, "Reallocate aPtr to the size aSize. The new pointer is returned.", py::arg("thePtr"), py::arg("theSize"));
cls_Standard_MMgrRaw.def("Free", (void (Standard_MMgrRaw::*)(Standard_Address)) &Standard_MMgrRaw::Free, "Free allocated memory. The pointer is nullified.", py::arg("thePtr"));

// CLASS: STANDARD_MMGRTBBALLOC
py::class_<Standard_MMgrTBBalloc, Standard_MMgrRoot> cls_Standard_MMgrTBBalloc(mod, "Standard_MMgrTBBalloc", "Implementation of OCC memory manager which uses Intel TBB scalable allocator.");

// Constructors
cls_Standard_MMgrTBBalloc.def(py::init<>());
cls_Standard_MMgrTBBalloc.def(py::init<const Standard_Boolean>(), py::arg("aClear"));

// Methods
cls_Standard_MMgrTBBalloc.def("Allocate", (Standard_Address (Standard_MMgrTBBalloc::*)(const Standard_Size)) &Standard_MMgrTBBalloc::Allocate, "Allocate aSize bytes", py::arg("aSize"));
cls_Standard_MMgrTBBalloc.def("Reallocate", (Standard_Address (Standard_MMgrTBBalloc::*)(Standard_Address, const Standard_Size)) &Standard_MMgrTBBalloc::Reallocate, "Reallocate aPtr to the size aSize. The new pointer is returned.", py::arg("thePtr"), py::arg("theSize"));
cls_Standard_MMgrTBBalloc.def("Free", (void (Standard_MMgrTBBalloc::*)(Standard_Address)) &Standard_MMgrTBBalloc::Free, "Free allocated memory", py::arg("thePtr"));

// CLASS: STANDARD_NOMOREOBJECT
py::class_<Standard_NoMoreObject, opencascade::handle<Standard_NoMoreObject>, Standard_DomainError> cls_Standard_NoMoreObject(mod, "Standard_NoMoreObject", "None");

// Constructors
cls_Standard_NoMoreObject.def(py::init<>());
cls_Standard_NoMoreObject.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_NoMoreObject.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_NoMoreObject::Raise, "None", py::arg("theMessage"));
cls_Standard_NoMoreObject.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_NoMoreObject::Raise, "None", py::arg("theMessage"));
cls_Standard_NoMoreObject.def_static("NewInstance_", (opencascade::handle<Standard_NoMoreObject> (*)(const Standard_CString)) &Standard_NoMoreObject::NewInstance, "None", py::arg("theMessage"));
cls_Standard_NoMoreObject.def_static("get_type_name_", (const char * (*)()) &Standard_NoMoreObject::get_type_name, "None");
cls_Standard_NoMoreObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_NoMoreObject::get_type_descriptor, "None");
cls_Standard_NoMoreObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_NoMoreObject::*)() const) &Standard_NoMoreObject::DynamicType, "None");

// CLASS: STANDARD_OVERFLOW
py::class_<Standard_Overflow, opencascade::handle<Standard_Overflow>, Standard_NumericError> cls_Standard_Overflow(mod, "Standard_Overflow", "None");

// Constructors
cls_Standard_Overflow.def(py::init<>());
cls_Standard_Overflow.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_Overflow.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_Overflow::Raise, "None", py::arg("theMessage"));
cls_Standard_Overflow.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_Overflow::Raise, "None", py::arg("theMessage"));
cls_Standard_Overflow.def_static("NewInstance_", (opencascade::handle<Standard_Overflow> (*)(const Standard_CString)) &Standard_Overflow::NewInstance, "None", py::arg("theMessage"));
cls_Standard_Overflow.def_static("get_type_name_", (const char * (*)()) &Standard_Overflow::get_type_name, "None");
cls_Standard_Overflow.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_Overflow::get_type_descriptor, "None");
cls_Standard_Overflow.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_Overflow::*)() const) &Standard_Overflow::DynamicType, "None");

// TYPEDEF: STANDARD_PBYTE
/*
*/

// CLASS: STANDARD_TOOMANYUSERS
py::class_<Standard_TooManyUsers, opencascade::handle<Standard_TooManyUsers>, Standard_LicenseError> cls_Standard_TooManyUsers(mod, "Standard_TooManyUsers", "None");

// Constructors
cls_Standard_TooManyUsers.def(py::init<>());
cls_Standard_TooManyUsers.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_TooManyUsers.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_TooManyUsers::Raise, "None", py::arg("theMessage"));
cls_Standard_TooManyUsers.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_TooManyUsers::Raise, "None", py::arg("theMessage"));
cls_Standard_TooManyUsers.def_static("NewInstance_", (opencascade::handle<Standard_TooManyUsers> (*)(const Standard_CString)) &Standard_TooManyUsers::NewInstance, "None", py::arg("theMessage"));
cls_Standard_TooManyUsers.def_static("get_type_name_", (const char * (*)()) &Standard_TooManyUsers::get_type_name, "None");
cls_Standard_TooManyUsers.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_TooManyUsers::get_type_descriptor, "None");
cls_Standard_TooManyUsers.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_TooManyUsers::*)() const) &Standard_TooManyUsers::DynamicType, "None");

// CLASS: STANDARD_UNDERFLOW
py::class_<Standard_Underflow, opencascade::handle<Standard_Underflow>, Standard_NumericError> cls_Standard_Underflow(mod, "Standard_Underflow", "None");

// Constructors
cls_Standard_Underflow.def(py::init<>());
cls_Standard_Underflow.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Standard_Underflow.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_Underflow::Raise, "None", py::arg("theMessage"));
cls_Standard_Underflow.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_Underflow::Raise, "None", py::arg("theMessage"));
cls_Standard_Underflow.def_static("NewInstance_", (opencascade::handle<Standard_Underflow> (*)(const Standard_CString)) &Standard_Underflow::NewInstance, "None", py::arg("theMessage"));
cls_Standard_Underflow.def_static("get_type_name_", (const char * (*)()) &Standard_Underflow::get_type_name, "None");
cls_Standard_Underflow.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_Underflow::get_type_descriptor, "None");
cls_Standard_Underflow.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_Underflow::*)() const) &Standard_Underflow::DynamicType, "None");


}

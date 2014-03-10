/**
 * @file character_tokenizer.h
 * @author Chase Geigle
 *
 * All files in META are released under the MIT license. For more details,
 * consult the file LICENSE in the root of the project.
 */

#ifndef META_CHARACTER_TOKENIZER_H_
#define META_CHARACTER_TOKENIZER_H_

#include "analyzers/token_stream.h"
#include "util/clonable.h"

namespace meta
{
namespace corpus
{
class document;
}
}

namespace meta
{
namespace analyzers
{

/**
 * Converts documents into streams of characters. This is the simplest
 * tokenizer.
 */
class character_tokenizer : public util::clonable<
                            token_stream, character_tokenizer>
{
  public:
    /**
     * Creates a character_tokenizer.
     */
    character_tokenizer();

    /**
     * Sets the content for the tokenizer.
     */
    void set_content(const std::string& content) override;

    /**
     * Obtains the next token in the document. This token will contain a
     * single character.
     */
    std::string next() override;

    /**
     * Determines if there are more tokens in the document.
     */
    operator bool() const override;

    /**
     * Identifier for this tokenizer.
     */
    const static std::string id;

  private:
    std::string content_;
    uint64_t idx_;
};
}
}

#endif
